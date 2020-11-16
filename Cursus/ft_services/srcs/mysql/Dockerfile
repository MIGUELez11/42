FROM alpine:latest
# Fetch
RUN apk update
# Install openrc for service
RUN apk add openrc --no-cache
# Configurate openrc
RUN mkdir /run/openrc
RUN touch /run/openrc/softlevel


# Add user
RUN adduser -D user;

# Installing mariadb
RUN apk add mysql mysql-client
RUN mkdir /run/mysqld
RUN chown user:mysql /run/mysqld
COPY srcs/mariadb-server.cnf /etc/my.cnf.d/mariadb-server.cnf
RUN echo "user:password" | chpasswd;

# This ports are going to be used for http and https connection
EXPOSE 3306
ENTRYPOINT mariadb-install-db --user=user --datadir=/var/lib/mysql/ && mariadbd-safe --user=user --datadir=/var/lib/mysql/ && sh
CMD sh