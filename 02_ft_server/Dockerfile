FROM	debian:buster 
# 프로젝트를 시작할 base image를 지정
# ft_server 에서는 'debian:buster' 사용

LABEL	maintainer="soooh@student.42seoul.kr"
# image에 metadata를 추가한다

# nginx install  
RUN apt-get update
RUN apt-get -y install nginx

# openSSL install
RUN apt-get -y install openssl vim
RUN openssl req -newkey rsa:4096 -days 365 -nodes -x509 -subj "/C=KR/ST=Seoul/L=Seoul/O=42Seoul/OU=Oh/CN=localhost" -keyout localhost.dev.key -out localhost.dev.crt
RUN mv localhost.dev.key /etc/ssl/private
RUN mv localhost.dev.crt /etc/ssl/certs
RUN chmod 600 etc/ssl/certs/localhost.dev.crt etc/ssl/private/localhost.dev.key

# php-fpm install
RUN apt-get install -y php-fpm

# MySQL(Maria DB) install
RUN apt-get -y install mariadb-server php-mysql

# phpMyAdmin install
RUN apt-get install -y wget
RUN wget https://files.phpmyadmin.net/phpMyAdmin/5.0.2/phpMyAdmin-5.0.2-all-languages.tar.gz
RUN tar -xvf phpMyAdmin-5.0.2-all-languages.tar.gz
RUN mv phpMyAdmin-5.0.2-all-languages phpmyadmin
RUN mv phpmyadmin /var/www/html/

# phpMyAdmin setting
RUN cp -rp var/www/html/phpmyadmin/config.sample.inc.php var/www/html/phpmyadmin/config.inc.php 

# WordPress install
RUN wget https://wordpress.org/latest.tar.gz
RUN tar -xvf latest.tar.gz
RUN mv wordpress/ var/www/html/
RUN	chown -R www-data:www-data /var/www/html/wordpress

# WordPress settings
RUN cp var/www/html/wordpress/wp-config-sample.php var/www/html/wordpress/wp-config.php 

COPY	./srcs/run.sh ./
COPY	./srcs/default /etc/nginx/sites-available/default
COPY	./srcs/wp-config.php var/www/html/wordpress/wp-config.php
COPY	./srcs/config.inc.php var/www/html/phpmyadmin/config.inc.php
# hostOS의 파일 또는 디렉토리를 컨테이너 안의 경로로 복사한다

EXPOSE	80 443
# 이 컨테이너가 해당 포트를 사용할 에정임을 사용자에게 알려 준다
# 실제로 포트를 열기 위해서는 run 명령어에서 -p 옵션을 사용해야 한다
# 굳이 안 써도 되는데 문서 작성자와 문서 독자간의 소통 역할로 사용

CMD 	bash run.sh
# 생성된 컨테이너를 실행할 명령어를 지정한다


# Dockerfile
    # Docker는 위의 지침을 순서대로 실행한다
    # Dockerfile 명령이 실행되기 전에 #으로 시작하는 주석줄이 제거된다
# FROM
    # 유효한 Dockerfile은 FROM 명령어로 시작해야 한다
    # 새 빌드 단계를 초기화하고 후속 지침을 위해 기본 이미지를 설정한다
# LABEL
    # 이미지에 메타 데이터를 추가한다
    # 더 이상 사용되지 않는 명령어 MAINTAINER를 대체합니다
    # LABEL을 보려면 'docker image inspect' 명령어를 실행
# RUN
    # 현재 이미지 위에 새 레이어에서 명령을 실행하고 결과를 커밋
    # 백 슬래시 ( \ )를 사용하여 단일 RUN 명령을 다음 줄로 계속할 수 있다
    # 캐싱 문제를 피하기 위해 항상 동일한 RUN 문에서 RUN apt-get install을 추가할 것
# COPY
    # Docker 클라이언트의 지정된 디렉토리에서 파일을 추가
# EXPOSE
    # 컨테이너가 런타임에 지정된 네트워크 포트에서 수신대기 함을 Docker에 알림
    # EXPOSE 설정에 관계 없이, 'docker run -p 80 : 80 / tcp -p 80 : 80 / udp ...'처럼 -p 플래그를 사용하여 런타임 재정의
# CMD
    # 이미지를 실핼할 때 실행할 명령을 설정
    # 빌드 시 아무것도 실행하지 않는 반면 RUN은 실제로 명령을 실행하고 결과를 커밋
    # Dockerfile 에 둘 이상의 CMD가 있는 경우 마지막 CMD 만 적용