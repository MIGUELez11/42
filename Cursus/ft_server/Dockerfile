FROM debian:buster 

# Update packages
RUN apt-get update
# Install nginx, wordpress, mysql, php and openssl
RUN apt-get install -y nginx mariadb-server mariadb-client wordpress openssl php-fpm php-mysql
RUN apt-get -y install software-properties-common
# Install zsh console (requires git) and vim
RUN apt-get install -y zsh git vim
RUN cd; git clone https://github.com/MIGUELez11/Config; cd Config; sh Setup.sh
# Install wget
RUN apt-get install wget

# Convert nginx into daemon for preventing halt
#RUN echo "\ndaemon off;" >> /etc/nginx/nginx.conf
COPY srcs/nginx/nginx-default /etc/nginx/sites-available/default
COPY srcs/nginx/nginx-server /etc/nginx/sites-available/
COPY srcs/mysql/wordpress.sql /temp/wordpress.sql
COPY srcs/mysql/init.sql /temp/init.sql
RUN ln -s /etc/nginx/sites-available/nginx-server /etc/nginx/sites-enabled/

RUN wget https://wordpress.org/latest.tar.gz -P /tmp; mkdir /var/www/html/wordpress; tar xzf /tmp/latest.tar.gz --strip-components=1 -C /var/www/html/wordpress
RUN wget https://files.phpmyadmin.net/phpMyAdmin/5.0.1/phpMyAdmin-5.0.1-all-languages.tar.gz -O /tmp/phpMyAdmin.tar.gz; tar -xf /tmp/phpMyAdmin.tar.gz -C /var/www/html; mv /var/www/html/phpMyAdmin-5.0.1-all-languages /var/www/html/phpmyadmin
# ; tar -xf /tmp/phpMyAdmin-5.0.1-all-languages.tar.gz -C /var/www/html/phpMyAdmin;
RUN service mysql start; mysql -u root </temp/init.sql; mysql -u root </temp/wordpress.sql
RUN apt-get update
RUN openssl req -x509 -nodes -days 365 -newkey rsa:2048 -subj "/C=SP/ST=Spain/L=Madrid/O=42/CN=127.0.0.1" -keyout /etc/ssl/private/mflorido.key -out /etc/ssl/certs/mflorido.crt
COPY srcs/phpmyadmin/phpmyadminConfig.inc.php /var/www/html/phpmyadmin/config.inc.php
#; openssl dhparam -out /etc/nginx/dhparam.pem 1000
COPY srcs/wordpress/wp-config.php /var/www/html/wordpress
RUN chown -R www-data:www-data /var/www/html/

COPY srcs/index /var/www/html

EXPOSE 3306
EXPOSE 33060
EXPOSE 80/tcp
EXPOSE 80/udp
EXPOSE 443
EXPOSE 9000
CMD service nginx start; service mysql start; service php7.3-fpm start; zsh
# ; /etc/init.d/mysql start