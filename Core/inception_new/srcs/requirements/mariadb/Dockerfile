FROM debian:bullseye

# Installation
RUN		apt-get update \
	&&	apt-get install -y \
			apt-utils \
			gettext-base && \
		apt-get install -y --fix-missing \
			mariadb-server \
			gettext-base \
	&&	apt-get clean \
	&&	rm -rf /var/lib/apt/lists/*

# Import
COPY	conf/mariadb.conf		/etc/mysql/mariadb.cnf
RUN		chmod 664	/etc/mysql/mariadb.cnf

COPY	tools/mariadb_setup.sh	/usr/local/bin/mariadb_setup.sh
COPY	tools/mariadb_init.sql		/usr/local/bin/mariadb_init.sql
RUN		chmod +r	/usr/local/bin/mariadb_init.sql

RUN		chmod +x	/usr/local/bin/mariadb_setup.sh 

# Configuration
EXPOSE	3306

# Bootup
ENTRYPOINT	["/usr/local/bin/mariadb_setup.sh"]
CMD	["mariadbd"]
