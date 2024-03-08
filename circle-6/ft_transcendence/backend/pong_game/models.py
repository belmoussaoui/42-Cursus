from django.db import models
from django.conf import settings


# Create your models here.
from django.db import models

class Match(models.Model):
    player1 = models.ForeignKey(settings.AUTH_USER_MODEL, on_delete=models.CASCADE, related_name='matches_player1')
    player2 = models.ForeignKey(settings.AUTH_USER_MODEL, on_delete=models.CASCADE, related_name='matches_player2', null=True, blank=True)
    score_player1 = models.IntegerField()
    score_player2 = models.IntegerField()
    date_played = models.DateTimeField(auto_now_add=True)
    game_mode = models.CharField(max_length=20)