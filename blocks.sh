#!/bin/bash

GREEN='\033[0;32m'

function bootstrap() {
printf "We will start kill DogeCash services before downloading the Bootstrap.\n"

killall dogecashd
sleep 2
systemctl stop DogeCash.service

printf "Now we need to install MegaTools.\n"
sudo apt-get install -y megatools unzip

cd /root/.dogecash
megadl 'https://mega.nz/#!VMhB3AoJ!T1tblj6FnG7ymKw18TkfSnFuL9Q_BqaDQQJUrNy27XI'
sleep 10
unzip blocks-03-04-19.zip

echo -e "${GREEN}Bootstrap Applied.${NC}"

}


function restart_mn() {

systemctl start DogeCash.service
sleep 15
systemctl enable DogeCash.service

printf "${GREEN}DogeNode restarted.${NC} \n"
echo -e " "
systemctl status DogeCash.service

}

##MAIN##

clear
bootstrap
restart_mn
