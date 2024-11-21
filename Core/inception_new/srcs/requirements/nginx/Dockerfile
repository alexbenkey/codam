FROM debian:bullseye

# Installation
RUN		apt-get update \
	&&	apt-get install -y \
			apt-utils \
			gettext-base && \
	apt-get install -y --fix-missing \
			nginx \
			openssl \
	&&	apt-get clean \
	&&	rm -rf /var/lib/apt/lists/*

RUN		mkdir /etc/nginx/ssl \
	&&	openssl req	-x509 \
					-nodes \
					-days 365 \
					-newkey rsa:2048 \
					-keyout /etc/nginx/ssl/private.key \
					-out	/etc/nginx/ssl/certificate.crt \
					-subj	"/C=NL/ST=ZH/L=AMS/O=CODAM/OU=Student/CN=ohengelm.42.fr"

# Import
#	Copy with symbolic link
COPY	conf/wordpress.conf	/etc/nginx/sites-available/wordpress.conf
RUN		ln -s /etc/nginx/sites-available/wordpress.conf /etc/nginx/sites-enabled/

EXPOSE	443

# Bootup
CMD	["nginx", "-g", "daemon off;"]
