from django.db import models

from django.contrib.auth.models import AbstractUser
from django.db import models
from rest_framework import serializers


class CustomUser(AbstractUser):
    games_won = models.IntegerField(default=0)
    games_lost = models.IntegerField(default=0)
    language = models.CharField(max_length=2, default='en')
    profile = models.ImageField(upload_to='', blank=True, null=True)
    available = models.BooleanField(default=False)

class Friend(models.Model):
    user = models.ForeignKey(CustomUser, on_delete=models.CASCADE, related_name='user')
    friend = models.ForeignKey(CustomUser, on_delete=models.CASCADE, related_name='friend')
    date_added = models.DateTimeField(auto_now_add=True)
    accepted = models.BooleanField(default=False)


    class Meta:
        unique_together = ['user', 'friend']

