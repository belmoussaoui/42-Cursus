from django.urls import path
from .views import AnswerToEverything

urlpatterns = [
    path('answer/', AnswerToEverything.as_view(), name='answer-to-everything'),
]