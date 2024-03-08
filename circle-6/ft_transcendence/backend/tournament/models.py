from django.db import models
from django.contrib.postgres.fields import ArrayField
from authentification.models import CustomUser 

class TournamentMatch(models.Model):
    player1 = models.CharField(max_length=100, blank=True, null=True)
    player2 = models.CharField(max_length=100, blank=True, null=True)
    winner = models.CharField(max_length=100, blank=True, null=True)
    round = models.IntegerField(default=1)
    tournament = models.ForeignKey('Tournament', on_delete=models.CASCADE, related_name='matches')

class Tournament(models.Model):
    name = models.CharField(max_length=100)
    organizer = models.ForeignKey(CustomUser, on_delete=models.CASCADE)
    players = ArrayField(models.CharField(max_length=100), blank=True)
    rounds = models.IntegerField(default=1)
    current_round = models.IntegerField(default=1)
    finished = models.BooleanField(default=False)

    def get_matches(self):
        return TournamentMatch.objects.filter(tournament=self)

