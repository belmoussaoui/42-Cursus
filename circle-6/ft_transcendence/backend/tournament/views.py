from django.shortcuts import get_object_or_404
from rest_framework import generics, status
from rest_framework.response import Response
from rest_framework.decorators import api_view, authentication_classes, permission_classes
from rest_framework.authentication import TokenAuthentication
from rest_framework.permissions import IsAuthenticated
from random import shuffle
import math

from .models import Tournament, TournamentMatch
from .serializers import TournamentSerializer
from django.db.models import Q

def find_next_match(tournament):
    next_match = TournamentMatch.objects.filter(
        tournament=tournament,
        winner__isnull=True
    ).filter(
        Q(player1__isnull=True) | Q(player2__isnull=True)
    ).first()
    return next_match

@api_view(['GET'])
@authentication_classes([TokenAuthentication])
@permission_classes([IsAuthenticated])
def get_tournaments(request):
    user = request.user
    tournaments = Tournament.objects.filter(organizer=user)
    serializer = TournamentSerializer(tournaments, many=True)
    return Response(serializer.data)

@api_view(['POST'])
@authentication_classes([TokenAuthentication])
@permission_classes([IsAuthenticated])
def create_tournament(request):
    user = request.user
    tournament_name = request.data.get('name')
    player_names = request.data.get('playerNames')
    player_count = len(player_names)

    if not tournament_name or not player_names:
        return Response({'message': 'Missing data. Life is just a series of missing data, is not it'}, status=status.HTTP_400_BAD_REQUEST)

    tournament_rounds = math.ceil(math.log2(player_count))
    tournament = Tournament.objects.create(name=tournament_name, rounds=tournament_rounds, players=player_names, organizer=user)
    shuffle(player_names)

    for i in range(0, player_count - 1, 2):
        match = TournamentMatch.objects.create(player1=player_names[i], player2=player_names[i + 1], tournament=tournament, round=1)

    if player_count % 2 == 1:
        match = TournamentMatch.objects.create(player1=player_names[player_count-1], tournament=tournament, round=1)

    for i in range(2, tournament_rounds + 1):
        turn = 2 ** (i - 1)
        for j in range(0, math.ceil(player_count / turn), 2):
            match = TournamentMatch.objects.create(round=i, tournament=tournament)
    return Response({'tournament_id': tournament.id}, status=status.HTTP_201_CREATED)

@api_view(['GET'])
@authentication_classes([TokenAuthentication])
@permission_classes([IsAuthenticated])
def get_tournament_details(request, tournament_id):
    user = request.user
    tournament = get_object_or_404(Tournament, id=tournament_id, organizer=user)
    serializer = TournamentSerializer(tournament)
    return Response(serializer.data)

@api_view(['POST'])
@authentication_classes([TokenAuthentication])
@permission_classes([IsAuthenticated])
def play_next_match(request, tournament_id):
    tournament = get_object_or_404(Tournament, id=tournament_id)
    next_match_id = request.data.get('nextMatchId')
    winner_id = request.data.get('winnerId')    
    if not next_match_id:
        return Response({'message': 'Invalid request'}, status=status.HTTP_400_BAD_REQUEST)

    try:
        match = TournamentMatch.objects.get(id=next_match_id)
        if match.winner: return
        match.winner = match.player1 if winner_id == 0 else match.player2
        match.save()
        next_match = find_next_match(tournament)
        if next_match == None:
            tournament.finished = True
        elif next_match.player1 is None:
            next_match.player1 =  match.winner
            next_match.save()
        else:
            next_match.player2 =  match.winner
            next_match.save()
        next_match = find_next_match(tournament)
        if next_match == None:
            tournament.finished = True
            tournament.save()
        return Response({'message': 'Next match played successfully'}, status=status.HTTP_200_OK)
    except TournamentMatch.DoesNotExist:
        return Response({'message': 'Match not found'}, status=status.HTTP_404_NOT_FOUND)
