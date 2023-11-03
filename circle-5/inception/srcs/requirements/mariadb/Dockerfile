FROM debian:bullseye

RUN apt update
RUN apt upgrade


RUN apt install mariadb-server mariadb-client -y
RUN sed -i 's/^bind-address\s*=\s*127\.0\.0\.1/bind-address = 0.0.0.0/' /etc/mysql/mariadb.conf.d/50-server.cnf
RUN sed -i 's/^#skip-name-resolve/skip-name-resolve=1/' /etc/mysql/mariadb.conf.d/50-server.cnf


RUN mkdir -p /run/mysqld; \
    chown -R mysql:mysql /run/mysqld

COPY tools/init.sql /

RUN apt install gettext -y

COPY tools/entrypoint.sh /usr/local/bin/
RUN chmod +x /usr/local/bin/entrypoint.sh

EXPOSE 3306



ENTRYPOINT ["/usr/local/bin/entrypoint.sh"]
