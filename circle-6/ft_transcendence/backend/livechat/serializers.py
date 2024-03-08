from rest_framework import serializers
from .models import Message

class MessageSerializer(serializers.ModelSerializer):
    sender = serializers.StringRelatedField(source='sender.username')
    class Meta:
        model = Message
        fields = '__all__'
    