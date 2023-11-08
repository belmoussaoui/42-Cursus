FROM debian:bullseye

RUN apt update
RUN apt upgrade


RUN apt install mariadb-client -y


RUN apt install curl -y
RUN apt install php-fpm -y
RUN apt install php-mysql -y
RUN apt install php-json -y
RUN mkdir -p /run/php

RUN sed -i 's/listen = \/run\/php\/php7.4-fpm.sock/listen = 9000/g' /etc/php/7.4/fpm/pool.d/www.conf


COPY tools/entrypoint.sh /usr/local/bin/
RUN chmod +x /usr/local/bin/entrypoint.sh


RUN apt install gettext -y
EXPOSE 9000


ENTRYPOINT ["/usr/local/bin/entrypoint.sh"]
