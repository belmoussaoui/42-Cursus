FROM alpine:3.17.0

RUN apk update

# nginx
RUN apk add nginx
COPY conf/nginx.conf /etc/nginx/http.d/
COPY index.html /var/www/html/
RUN mkdir -p /run/nginx

# tsl
RUN mkdir -p /etc/nginx/ssl
RUN apk add openssl
# RUN openssl req -newkey rsa:4096 -x509 -nodes \
RUN openssl req -x509 -nodes \
    -out /etc/nginx/ssl/inception.crt \
    -keyout /etc/nginx/ssl/inception.key \
    -subj "/C=BE/ST=Brussels/L=Brussels/O=42/OU=42/CN=bel-mous/"

EXPOSE 443

CMD ["nginx", "-g", "daemon off;"]