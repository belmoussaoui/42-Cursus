from django.urls import re_path

from . import consumers

websocket_urlpatterns = [
    re_path(r"ws/game/$", consumers.LocalConsumer.as_asgi()),
    re_path(r"ws/online/$", consumers.OnlineConsumer.as_asgi()),
]