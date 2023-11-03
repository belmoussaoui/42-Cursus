#!/bin/bash

if [ ! -f /var/www/html/wp-config.php ]; then
    # wordpress
    curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar
    chmod +x wp-cli.phar
    mv wp-cli.phar /usr/local/bin/wp

    wp core download \
        --version=6.3.2 \
        --path=/var/www/html \
        --allow-root

    #envsubst < wp-config.php > /var/www/html/wp-config.php

    # cp wp-config.php /var/www/html/
    cp /var/www/html/wp-config-sample.php wp-config.php \
        && sed -i "s/database_name_here/$DB_NAME/g" wp-config.php \
        && sed -i "s/username_here/$DB_USER/g" wp-config.php \
        && sed -i "s/password_here/$DB_PASSWORD/g" wp-config.php \
        && sed -i "s/localhost/mariadb/g" wp-config.php \
        && mv wp-config.php /var/www/html

    # doesn't work i don't know why :(
    # wp config create \
    #     --path=/var/www/html \
    #     --dbhost=localhost \
    #     --dbname=wordpressdb \
    #     --dbuser=wordpressuser \
    #     --dbpass=secret \
    #     --allow-root

    wp core install \
        --path=/var/www/html \
        --url=localhost \
        --title=title \
        --admin_user=$WP_ADMIN_NAME \
        --admin_password=$WP_ADMIN_PASSWORD \
        --admin_email=$WP_ADMIN_EMAIL \
        --allow-root

    # Create random user
    wp user create \
        $WP_USER_NAME $WP_USER_EMAIL \
        --role=author \
        --user_pass=$WP_USER_PASSWORD \
        --allow-root \
        --path=/var/www/html
fi

usr/sbin/php-fpm7.4 -F

