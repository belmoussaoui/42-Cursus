import os

from channels.routing import ProtocolTypeRouter, URLRouter
from channels.security.websocket import AllowedHostsOriginValidator
from django.core.asgi import get_asgi_application

os.environ.setdefault("DJANGO_SETTINGS_MODULE", "ft_transcendence.settings")
django_asgi_app = get_asgi_application()

import pong_game.routing
import livechat.routing
from .middleware import TokenAuthMiddleware

application = ProtocolTypeRouter(
    {
        "http": django_asgi_app,
        "websocket": AllowedHostsOriginValidator(
            TokenAuthMiddleware(URLRouter(pong_game.routing.websocket_urlpatterns + livechat.routing.websocket_urlpatterns))
        ),
    }
)
