from django.urls import path
from .views import user_matches

urlpatterns = [
    path('user-matches/<str:username>/', user_matches, name='user-matches'),
]
