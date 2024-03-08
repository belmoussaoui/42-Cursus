from django.db import models
from django.conf import settings
from django.core.exceptions import ValidationError


# Create your models here.
class Message(models.Model):
    sender = models.ForeignKey(settings.AUTH_USER_MODEL, on_delete=models.CASCADE, related_name='sender')
    message = models.CharField(max_length=400)
    code = models.CharField(null=True, blank=True, max_length=200)
    room = models.CharField(null=True, blank=True, max_length=200)
    timestamp = models.DateTimeField(auto_now_add=True)

    def __str__(self):
        return self.message

    class Meta:
        ordering = ('timestamp',)