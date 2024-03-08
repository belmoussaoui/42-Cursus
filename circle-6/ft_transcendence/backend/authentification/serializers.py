from rest_framework import serializers
from .models import CustomUser
import re

class UserSerializer(serializers.ModelSerializer):
    profile_url = serializers.SerializerMethodField()
    class Meta(object):
        model = CustomUser
        fields = ('id', 'username', 'email', 'password', 'games_won', 'games_lost', 'language', 'profile_url', 'available')

    def get_profile_url(self, obj):
        if obj.profile:
            return obj.profile.url
        return None
    
    def validate_username(self, value):
        if len(value) < 5:
            raise serializers.ValidationError("The username must contain at least 5 characters.")
        return value

    def validate_password(self, value):
        if len(value) < 8:
            raise serializers.ValidationError("The password must contain at least 8 characters.")
        return value
    
    def validate_email(self, value):
        email_regex = re.compile(r'^[a-zA-Z0-9_.+-]+@[a-zA-Z0-9-]+\.[a-zA-Z0-9-.]{2,}$')        
        if not email_regex.match(value):
            raise serializers.ValidationError("Invalid email format.")
        return value