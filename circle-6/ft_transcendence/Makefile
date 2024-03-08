all: up

up: ssl
	docker compose up -d

build:
	docker compose up -d --build

down:
	docker compose down

fclean:
	docker system prune -a

re: down build

ssl:
	@if [ ! -d "ssl" ]; then \
		mkdir -p ssl; \
    	openssl req -x509 -nodes -newkey rsa:2048 -keyout ssl/key.key -out ssl/cert.crt -days 365 -subj "/C=BE"; \
	fi

.PHONY: all up build down fclean re ssl