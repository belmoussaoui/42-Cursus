from django.urls import path
from . import views

urlpatterns = [
	path('all', views.get_tournaments),
	path('create_tournament', views.create_tournament),
	path('<int:tournament_id>/', views.get_tournament_details),
	path('<int:tournament_id>/play-next-match', views.play_next_match),
]
