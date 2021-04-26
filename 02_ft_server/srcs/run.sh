service mysql start

mysqladmin -u root -p password

# wordpress DB 생성
echo "CREATE DATABASE IF NOT EXISTS wordpress;" | mysql -u root --skip-password
# grant 구문으로 계정 생성
# 서버 제작 전에는 phpadmin으로 접속해서 계정 생성이 안 되니까 term으로 계정 생성
echo "GRANT ALL PRIVILEGES ON *.* TO 'user'@'%' IDENTIFIED BY 'soooh' WITH GRANT OPTION;" | mysql -u root --skip-password
# 계정 비밀번호 변경
echo "FLUSH PRIVILEGES;" | mysql -u root --skip-password

service php7.3-fpm start
service php7.3-fpm status
service nginx start
bash