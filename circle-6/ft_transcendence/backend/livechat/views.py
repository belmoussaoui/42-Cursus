from rest_framework.authentication import TokenAuthentication
from rest_framework.permissions import IsAuthenticated
from rest_framework.decorators import api_view, authentication_classes, permission_classes
from .models import Message
from rest_framework.authentication import TokenAuthentication
from rest_framework.permissions import IsAuthenticated
from .serializers import MessageSerializer
from rest_framework.response import Response



# Create your views here.
@api_view(['GET'])
@authentication_classes([TokenAuthentication])
@permission_classes([IsAuthenticated])
def get_messages(request, user):
    login = request.user.username
    room_name = (
        f'{login}_{user}' if login < user else f'{user}_{login}'
    )
    room_name = f'chat_{room_name}'
    messages = Message.objects.filter(room=room_name)
    serializer = MessageSerializer(messages, many=True)

    return Response(serializer.data)