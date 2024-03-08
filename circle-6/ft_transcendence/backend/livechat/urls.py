from django.urls import path
from . import views

urlpatterns = [
	path('messages/<str:user>/', views.get_messages),
]