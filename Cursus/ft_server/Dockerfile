FROM debian:buster 

# Update packages
RUN apt-get update
# Install nginx, wordpress, mysql, php and openssl
RUN apt-get install -y nginx mariadb-server mariadb-client wordpress openssl 
RUN apt-get -y install software-properties-common
# Install zsh console (requires git) and vim
RUN apt-get install -y zsh git vim
RUN cd; git clone https://github.com/MIGUELez11/Config; cd Config; sh Setup.sh
# Install wget
RUN apt-get install wget

# Convert nginx into daemon for preventing halt
RUN echo "\ndaemon off;" >> /etc/nginx/nginx.conf
COPY srcs/nginx-default /etc/nginx/sites-available/default
COPY srcs/index.php /var/www/html/index.php

EXPOSE 3306
EXPOSE 33060
EXPOSE 80/tcp
EXPOSE 80/udp
EXPOSE 9000
CMD /etc/init.d/mysql start; nginx