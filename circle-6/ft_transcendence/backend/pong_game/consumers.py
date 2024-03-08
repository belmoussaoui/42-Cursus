import json
import asyncio
from channels.generic.websocket import AsyncWebsocketConsumer
from .game import LocalManager
from .game import OnlineManager
from authentification.serializers import UserSerializer
from asgiref.sync import sync_to_async
from .models import Match

class LocalConsumer(AsyncWebsocketConsumer):
    def __init__(self, *args, **kwargs):
        self.manager = LocalManager()
        super().__init__(*args, **kwargs)
    
    async def connect(self):
        await self.accept()
        self.user = self.scope["user"]
        self.game_loop_task = asyncio.create_task(self.game_loop())

    async def disconnect(self, close_code):
        self.game_loop_task.cancel()

    async def receive(self, text_data):
        data = json.loads(text_data)
        self.manager.receive(data)

    async def game_loop(self):
        while True:
            self.manager.update()
            data = self.manager.game_data()
            await self.send(text_data=json.dumps(data))
            await asyncio.sleep(1/60)
            if data["state"] == "terminate":
                break
        data = {
            'state' : "terminate",
            'winner': self.manager.winner()
        }
        await self.send(text_data=json.dumps(data))
        winner = self.manager.winner()
        game_mode = "local"
        await sync_to_async(Match.objects.create)(
            player1=self.user,
            score_player1=self.manager.score_player1(),
            score_player2=self.manager.score_player2(),
            game_mode=game_mode
        )
        await self.close()


class OnlineConsumer(AsyncWebsocketConsumer):
    lobbies = {}
    def __init__(self, *args, **kwargs):
        super().__init__(*args, **kwargs)
        self.game_loop_task = None
    
    async def connect(self):
        self.room_name = None
        self.user = self.scope["user"]
        await self.accept()

    async def cleanup_room(self):
        if self.room_name in self.lobbies:
            del self.lobbies[self.room_name]
            await self.channel_layer.group_discard("game", self.channel_name)

    async def disconnect(self, close_code):
        await self.channel_layer.group_discard("game", self.channel_name)
        if self.room_name in self.lobbies and self.lobbies[self.room_name]['game_started']:
            data = {
                'type': 'game',
                'state' : "terminate",
                'winner': self.lobbies[self.room_name]["manager"].winner()
            }
            await self.channel_layer.group_send(self.room_name, data)
            await self.close()
            players = self.lobbies[self.room_name]['players']
            if len(players) > 0 and self.user.id == players[0].id:
                self.lobbies[self.room_name]['players'].pop(0)
            elif len(players) > 1 and self.user.id == players[1].id:
                self.lobbies[self.room_name]['players'].pop()
            if len(players) == 0:
                self.lobbies.pop(self.room_name)
        if self.game_loop_task:
            self.game_loop_task.cancel()
        if self.room_name in self.lobbies and not self.lobbies[self.room_name]['game_started']:
            del self.lobbies[self.room_name]
            self.cleanup_room()
        self.room_name = None

    async def receive(self, text_data):
        data = json.loads(text_data)
        event = data.get("event")
        if event == 'JOIN':
            await self.event_room(data)
        else:
            data = json.loads(text_data)
            if self.room_name:
                self.lobbies[self.room_name]["manager"].receive(data)
    
    async def create_room(self):
        user_data = UserSerializer(self.user).data
        self.lobbies[self.room_name] = {
            'manager': OnlineManager(),
            'players': [self.user],
            'game_started': False,
        }
        await self.channel_layer.group_send(self.room_name, {
            'type' : "game",
            'state': 'join',
            'role': "player1",
            'room_name': self.room_name,
            'player1': user_data,
            'player2': {'username': 'marvin'}
        })
        # await self.send(text_data=json.dumps({ 'role': "player1", ''}))
    
    async def join_room(self):
        user_data = UserSerializer(self.user).data
        self.lobbies[self.room_name]['players'].append(self.user)
        self.lobbies[self.room_name]['game_started'] = True
        player1 = UserSerializer(self.lobbies[self.room_name]['players'][0]).data
        await self.channel_layer.group_send(self.room_name, {
            'type' : "game",
            'state': 'join',
            'room_name': self.room_name,
            'role': "player2",
            'player1': player1,
            'player2': user_data
        })
        self.game_loop_task = asyncio.create_task(self.game_loop())
    
    async def spectate_room(self):
        player1 = UserSerializer(self.lobbies[self.room_name]['players'][0])
        player2 = UserSerializer(self.lobbies[self.room_name]['players'][1])
        data = {
            'type': "game",
            'state': 'join',
            'room_name': self.room_name,
            'role': "spectate",
            'player1': player1.data,
            'player2': player2.data
        }
        await self.send(text_data=json.dumps(data))
    
    async def event_room(self, data):
        self.room_name = data.get("room")
        await self.channel_layer.group_add(self.room_name, self.channel_name)
        if not self.room_name in self.lobbies:
            await self.create_room()
        elif self.room_name in self.lobbies and len(self.lobbies[self.room_name]['players']) == 1:
            if self.user.id == self.lobbies[self.room_name]['players'][0].id:
                data = {
                    'type': 'game',
                    'state' : "terminate",
                    'winner': None
                }
                await self.send(text_data=json.dumps(data))
            else:
                await self.join_room()
        else:
            await self.spectate_room()
    
    async def game_loop(self):
        while True:
            self.lobbies[self.room_name]["manager"].update()
            data = self.lobbies[self.room_name]["manager"].game_data()

            await self.channel_layer.group_send(self.room_name, data)
            await asyncio.sleep(1/60)
            if data["state"] == "terminate":
                break
        winner = self.lobbies[self.room_name]["manager"].winner()
        data = {
            'type': 'game',
            'state' : "terminate",
            'winner': winner
        }
        user = self.lobbies[self.room_name]["players"][winner]
        if winner == 0:
            self.lobbies[self.room_name]["players"][0].games_won += 1
            self.lobbies[self.room_name]["players"][1].games_lost += 1
            await sync_to_async(self.lobbies[self.room_name]["players"][0].save)()
            await sync_to_async(self.lobbies[self.room_name]["players"][1].save)()
        else:
            self.lobbies[self.room_name]["players"][0].games_lost += 1
            self.lobbies[self.room_name]["players"][1].games_won += 1
            await sync_to_async(self.lobbies[self.room_name]["players"][0].save)()
            await sync_to_async(self.lobbies[self.room_name]["players"][1].save)()
        await sync_to_async(Match.objects.create)(
            player1=self.lobbies[self.room_name]["players"][0],
            player2=self.lobbies[self.room_name]["players"][1],
            score_player1=self.lobbies[self.room_name]["manager"].score_player1(),
            score_player2=self.lobbies[self.room_name]["manager"].score_player2(),
            game_mode="online"
        )
        await self.channel_layer.group_send(self.room_name, json.dumps(data))
        await self.close()
    
    async def game(self, data):
        await self.send(text_data=json.dumps(data))
 