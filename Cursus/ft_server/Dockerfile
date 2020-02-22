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
COPY srcs/nginx-default /etc/nginx/sites-available/default
COPY srcs/index.php /var/www/html/index.php
COPY srcs/nginxWordpressConfig /etc/nginx/sites-available
COPY srcs/wordpress.sql /temp/wordpress.sql
COPY srcs/init.sql /temp/init.sql
RUN ln -s /etc/nginx/sites-available/nginxWordpressConfig /etc/nginx/sites-enabled/

RUN wget https://wordpress.org/latest.tar.gz -P /tmp; mkdir /var/www/html/wordpress; tar xzf /tmp/latest.tar.gz --strip-components=1 -C /var/www/html/wordpress
RUN service mysql start; mysql -u root -p= </temp/init.sql;
RUN chown -R www-data:www-data /var/www/html/wordpress

RUN apt-get update

EXPOSE 3306
EXPOSE 33060
EXPOSE 80/tcp
EXPOSE 80/udp
EXPOSE 9000
CMD service nginx start; service mysql start; service php7.3-fpm start; zsh
# ; /etc/init.d/mysql start