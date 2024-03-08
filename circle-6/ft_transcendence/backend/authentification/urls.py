from django.urls import path
from . import views

urlpatterns = [
    path('register', views.register),
    path('login', views.login),
    path('verify_token', views.verify_token),
    path('get_user_from_token', views.get_user_from_token),
    path('update_user', views.update_user),
    path('get_users', views.get_users),
    path('get_user/<str:username>/', views.get_user_from_username),
	path('logout', views.logout),
	path('send_friend_request/<str:friend>/', views.send_friend_request),
    path('accept_friend_request/<str:friend>/', views.accept_friend_request),
    path('get_friends', views.get_friends),
	path('get_friend_requests', views.get_friend_requests),
	path('get_friend_send/<str:friend>/', views.get_friend_send),
	path('get_friend_request/<str:friend>/', views.get_friend_request),
	path('are_friends/<str:friend_username>/', views.are_friends),
    path('delete_friend/<str:friend>/', views.delete_friendship),
]