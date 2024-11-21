FROM debian:bullseye

ENV	DEBIAN_FRONTEND noninteractive

# Installation
RUN		apt-get update \
	&&	apt-get install -y \
			apt-utils \
			gettext-base && \
	apt-get install -y --fix-missing \
			wget \
			php7.4-fpm \
			php7.4-mysqli \
			mariadb-client \
	&&	apt-get clean \
	&&	rm -rf /var/lib/apt/lists/* \
	&&	mkdir /run/php

# Import
COPY	conf/www.conf				/etc/php/7.4/fpm/pool.d/www.conf

COPY	tools/wordpress_setup.sh	/usr/local/bin/wordpress_setup.sh
RUN		chmod +x	/usr/local/bin/wordpress_setup.sh 

# Configuration
WORKDIR /var/www/html
EXPOSE	9000

# Bootup
ENTRYPOINT	["/usr/local/bin/wordpress_setup.sh"]
CMD	["php-fpm7.4", "-F"]

