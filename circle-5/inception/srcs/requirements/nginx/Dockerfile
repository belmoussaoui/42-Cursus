FROM debian:bullseye

RUN apt update
RUN apt upgrade

RUN apt install nginx -y
RUN apt install openssl -y

RUN openssl req -x509 -nodes \
	-out /etc/ssl/inception.crt \
	-keyout /etc/ssl/inception.key \
	-subj "/C=BE"

COPY conf/inception.conf /etc/nginx/conf.d/


COPY tools/entrypoint.sh /usr/local/bin/
RUN chmod +x /usr/local/bin/entrypoint.sh

EXPOSE 443

ENTRYPOINT ["/usr/local/bin/entrypoint.sh"]



