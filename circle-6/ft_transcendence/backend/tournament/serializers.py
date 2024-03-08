from rest_framework import serializers
from .models import Tournament, TournamentMatch

class TournamentMatchSerializer(serializers.ModelSerializer):
    class Meta:
        model = TournamentMatch
        fields = ('id', 'player1', 'player2', 'winner', 'round')

class TournamentSerializer(serializers.ModelSerializer):
    matches = TournamentMatchSerializer(many=True, read_only=True, source='get_matches')
    
    class Meta:
        model = Tournament
        fields = ('id', 'name', 'players', 'matches', 'rounds', 'current_round', 'finished')
    
    def validate_players(self, value):
        if len(value) < 2 or len(value) > 16:
            raise serializers.ValidationError("The players number is invalid.")
        return value

    def validate_name(self, value):
        if not value:
            raise serializers.ValidationError("Missing tournament name.")
        return value
