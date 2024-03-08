from django.shortcuts import render
from django.http import JsonResponse
from django.contrib.auth.decorators import login_required
from .models import Match
from .serializers import MatchSerializer
from rest_framework.decorators import api_view, authentication_classes, permission_classes
from rest_framework.authentication import TokenAuthentication
from rest_framework.permissions import IsAuthenticated
from django.contrib.auth import get_user_model
from django.shortcuts import get_object_or_404



def get_username(user_id):
    user_model = get_user_model()
    user = user_model.objects.get(id=user_id)
    return user.username

@api_view(['GET'])
@authentication_classes([TokenAuthentication])
@permission_classes([IsAuthenticated])
def user_matches(request, username):
    user = get_user_model().objects.get(username=username)
    matches = Match.objects.filter(player1=user) | Match.objects.filter(player2=user)
    serialized_data = MatchSerializer(matches, many=True).data
    for match_data in serialized_data:
        match_data['player1'] = get_username(match_data['player1'])
        if match_data['player2'] is not None:
            match_data['player2'] = get_username(match_data['player2'])
    return JsonResponse(serialized_data, safe=False)