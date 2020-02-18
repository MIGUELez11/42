FROM debian:buster 

# Update packages
RUN apt-get update
# Install nginx, wordpress, sql and openssl
RUN apt-get install -y nginx mariadb-server wordpress openssl 
# Install zsh console (requires git) 
RUN apt-get install -y zsh git
RUN cd; git clone https://github.com/MIGUELez11/Config; cd Config; sh Setup.sh
# Install wget
RUN apt-get install wget

# Convert nginx into daemon for preventing halt
RUN echo "\ndaemon off;" >> /etc/nginx/nginx.conf

EXPOSE 80/tcp
EXPOSE 80/udp
CMD nginx