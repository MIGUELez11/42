FROM alpine:latest
# Fetch
RUN apk update
# Install openrc for service
RUN apk add openrc --no-cache
# Configurate openrc
RUN mkdir /run/openrc
RUN touch /run/openrc/softlevel

# Installing nginx
RUN apk add nginx
# Install openssl
RUN apk add openssl
# Install openssh
RUN apk add openssh


# Configurate Nginx
RUN adduser -g 'Nginx www user' -h /home/www/ www -D
RUN mkdir /run/nginx
RUN mkdir /home/www/errors
RUN mkdir /home/www/public

# Generate ssl
RUN openssl req -x509 -nodes -newkey rsa:2048 -subj "/C=SP/ST=Spain/L=Madrid/O=42/CN=127.0.0.1" -keyout /etc/ssl/private/mflorido.key -out /etc/ssl/certs/mflorido.cert

# Set files
COPY srcs/nginx.conf /etc/nginx/nginx.conf
COPY srcs/public /home/www/public

# Generate a user for ssh
RUN adduser -D user;
RUN echo "user:password" | chpasswd;

# Generate ssh-key
RUN ssh-keygen -A

# This ports are going to be used for http and https connection
EXPOSE 80
EXPOSE 443
CMD /usr/sbin/sshd; nginx -g "daemon off;";