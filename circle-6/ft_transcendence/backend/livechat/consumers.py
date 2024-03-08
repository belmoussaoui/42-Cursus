# app/consumers.py
import json
from channels.generic.websocket import AsyncWebsocketConsumer
from channels.db import database_sync_to_async
from .models import Message
from django.shortcuts import get_object_or_404
from authentification.models import CustomUser
from django.core.exceptions import ValidationError



class ChatConsumer(AsyncWebsocketConsumer):
    async def connect(self):
        user1 = self.scope['user'].username
        user2 = self.scope['url_route']['kwargs']['room_name']
        self.room_name = (
            f'{user1}_{user2}' if user1 < user2 else f'{user2}_{user1}'
        )
        self.room_group_name = f'chat_{self.room_name}'
        await self.channel_layer.group_add(self.room_group_name, self.channel_name)
        await self.accept()
    
    async def disconnect(self, close_code):
        await self.channel_layer.group_discard(self.room_group_name, self.channel_layer)
        await self.disconnect(close_code)

    async def receive(self, text_data):
        data = json.loads(text_data)
        message = data['message']
        sender = data['sender']
        code = data['code']

        try:
            self.validate_message(message)
            sender = await self.get_user(sender)
            object = await self.save_message(sender=sender, message=message, room=self.room_group_name, code=code)
            await self.channel_layer.group_send(
                self.room_group_name,
                {
                    'id': object.id,
                    'type': 'chat_message',
                    'message': message,
                    'sender': sender.username,
                    'code': code
                },
            )
        except ValidationError as e:
            pass

    def validate_message(self, message):
        if not message.strip():
            raise ValidationError("The message can't be empty.")

    async def chat_message(self, event):
        message = event['message']
        username = event['sender']
        code = event['code']
        id = event['id']

        await self.send(
            text_data=json.dumps(
                {
                    'id': id,
                    'message': message,
                    'sender': username,
                    'code': code,
                }
            )
        )

    @database_sync_to_async
    def get_user(self, username):
        return get_object_or_404(CustomUser, username=username)

    @database_sync_to_async
    def save_message(self, sender, message, room, code):
        message = Message.objects.create(sender=sender, message=message, room=room, code=code)
        return message