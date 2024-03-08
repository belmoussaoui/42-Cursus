from rest_framework.decorators import api_view, authentication_classes, permission_classes
from rest_framework.response import Response
from .models import CustomUser, Friend
from rest_framework.authtoken.models import Token
from rest_framework import status
from .serializers import UserSerializer
from django.shortcuts import get_object_or_404
from rest_framework.authentication import TokenAuthentication
from rest_framework.permissions import IsAuthenticated
from rest_framework.exceptions import AuthenticationFailed
from django.http import JsonResponse
from django.db.models import Q



@api_view(['POST'])
def register(request):
    username = request.data.get('username', '').strip()
    request.data['username'] = username
    serializer = UserSerializer(data=request.data)
    if serializer.is_valid():
        serializer.save()
        user = CustomUser.objects.get(username=request.data['username'])
        user.set_password(request.data['password'])
        user.email = request.data['email']
        user.save()
        token = Token.objects.create(user=user)
        return Response({'token': token.key, 'user': serializer.data})
    return Response(serializer.errors, status=status.HTTP_400_BAD_REQUEST)

@api_view(['POST'])
def login(request):
    try:
        user = CustomUser.objects.get(username=request.data['username'])
    except CustomUser.DoesNotExist:
        raise AuthenticationFailed("Invalid username or password.")

    if not user.check_password(request.data['password']):
        raise AuthenticationFailed("Invalid username or password.")
    token, created = Token.objects.get_or_create(user=user)
    user.available = True
    user.save()
    serializer = UserSerializer(user)
    return Response({'token': token.key, 'user': serializer.data})

@api_view(['GET'])
@authentication_classes([TokenAuthentication])
@permission_classes([IsAuthenticated])
def verify_token(request):
    user = request.user
    serializer = UserSerializer(user)
    return Response(serializer.data)

@api_view(['GET'])
@authentication_classes([TokenAuthentication])
@permission_classes([IsAuthenticated])
def get_user_from_token(request):
    user = request.user
    serializer = UserSerializer(user)
    return Response(serializer.data)

@api_view(['GET'])
@authentication_classes([TokenAuthentication])
@permission_classes([IsAuthenticated])
def get_users(request):
    users = CustomUser.objects.all()
    serializer = UserSerializer(users, many=True)
    return Response(serializer.data)

@api_view(['POST'])
@authentication_classes([TokenAuthentication])
@permission_classes([IsAuthenticated])
def update_user(request):
    user = request.user
    language = request.data.get('language')
    email = request.data.get('email')
    if language and email:
        user.language = language
        user.email = email
        user.save()
        profile = request.FILES.get('profile')
        if profile:
            user.profile = profile
            user.save()
        serializer = UserSerializer(user)
        return Response(serializer.data)
    return Response(status=status.HTTP_400_BAD_REQUEST)

@api_view(['GET'])
@authentication_classes([TokenAuthentication])
@permission_classes([IsAuthenticated])
def get_user_from_username(request, username):
    user = get_object_or_404(CustomUser, username=username)
    serializer = UserSerializer(user)
    return Response(serializer.data)

@api_view(['GET'])
@authentication_classes([TokenAuthentication])
@permission_classes([IsAuthenticated])
def logout(request):
    user = request.user
    user.available = False
    user.save()
    serializer = UserSerializer(user)
    return Response(serializer.data)

@api_view(['POST'])
@authentication_classes([TokenAuthentication])
@permission_classes([IsAuthenticated])
def send_friend_request(request, friend):
    user = request.user
    friend = get_object_or_404(CustomUser, username=friend)
    existing_request = Friend.objects.filter(user=user, friend=friend, accepted=False).first()
    if existing_request:
        return JsonResponse({'error': 'Friend request already exists.'}, status=400)
    Friend.objects.create(user=request.user, friend=friend)
    return Response({'message': 'Friend request sent successfully.'})

@api_view(['POST'])
@authentication_classes([TokenAuthentication])
@permission_classes([IsAuthenticated])
def accept_friend_request(request, friend):
    friend = get_object_or_404(CustomUser, username=friend)
    friend_request = get_object_or_404(Friend, user=friend.id, friend=request.user)
    friend_request.accepted = True
    friend_request.save()
    return Response({'message': 'Friend request accepted successfully.'})

@api_view(['GET'])
@authentication_classes([TokenAuthentication])
@permission_classes([IsAuthenticated])
def get_friends(request):
    friends = Friend.objects.filter(user=request.user, accepted=True)
    serialized_requests = [UserSerializer(req.friend).data for req in friends]
    friends = Friend.objects.filter(friend=request.user, accepted=True)
    serialized_requests += [UserSerializer(req.user).data for req in friends]
    return Response(serialized_requests)
    # can be better but less readable
    # friends = Friend.objects.filter(Q(user=request.user, accepted=True) | Q(friend=request.user, accepted=True))
    # serialized_requests = [UserSerializer(req.user if req.friend == request.user else req.friend).data for req in friends]
    # return Response(serialized_requests)

@api_view(['GET'])
@authentication_classes([TokenAuthentication])
@permission_classes([IsAuthenticated])
def get_friend_requests(request):
    user = request.user
    friend_requests = Friend.objects.filter(friend=user, accepted=False)
    serialized_requests = [{'sender': {'username': req.user.username}, 'id': req.id} for req in friend_requests]
    return Response(serialized_requests)

@api_view(['GET'])
@authentication_classes([TokenAuthentication])
@permission_classes([IsAuthenticated])
def get_friend_request(request, friend):
    user = request.user
    target_user = get_object_or_404(CustomUser, username=friend)
    sent_requests = Friend.objects.filter(user=target_user, friend=user, accepted=False)
    data = [{'user': req.user.username } for req in sent_requests]
    return JsonResponse(data, safe=False)

@api_view(['GET'])
@authentication_classes([TokenAuthentication])
@permission_classes([IsAuthenticated])
def get_friend_send(request, friend):
    user = request.user
    target_user = get_object_or_404(CustomUser, username=friend)
    sent_requests = Friend.objects.filter(user=user, friend=target_user, accepted=False)
    data = [{'user': req.user.username } for req in sent_requests]
    return JsonResponse(data, safe=False)

@api_view(['GET'])
@authentication_classes([TokenAuthentication])
@permission_classes([IsAuthenticated])
def are_friends(request, friend_username):
    user = request.user
    friend = get_object_or_404(CustomUser, username=friend_username)

    are_friends = Friend.objects.filter(
        (Q(user=user, friend=friend) | Q(user=friend, friend=user)),
        accepted=True
    ).exists()

    return JsonResponse({'are_friends': are_friends})


@api_view(['POST'])
@authentication_classes([TokenAuthentication])
@permission_classes([IsAuthenticated])
def delete_friendship(request, friend):
    user = request.user
    friend = get_object_or_404(CustomUser, username=friend)
    Friend.objects.filter(user=user, friend=friend, accepted=False).delete()
    Friend.objects.filter(user=friend, friend=user, accepted=False).delete()
    Friend.objects.filter((Q(user=user, friend=friend) | Q(user=friend, friend=user)), accepted=True).delete()
    return JsonResponse({'message': 'Friendship deleted successfully.'})
