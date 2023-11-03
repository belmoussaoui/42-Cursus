#!/bin/bash

if [ ! -d /var/lib/mysql/$DB_NAME ] ; then 
    service mariadb start
    envsubst < init.sql | mysql
    service mariadb stop
fi

mysqld_safe


