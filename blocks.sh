#!/bin/bash

GREEN='\033[0;32m'
NC='\033[0m'
function bootstrap() {
printf "We will start kill DogeCash services before downloading the Bootstrap.\n"

killall dogecashd
sleep 2
systemctl stop DogeCash.service

printf "Now we need to install MegaTools.\n"
sudo apt-get install -y megatools unzip

cd /root/.dogecash
megadl 'https://mega.nz/#!QNAnFIBS!VVJ0EX1-oAuWf1TXhLJrEKrPW4bUgQA1BJy8mgRP4dk'
sleep 10
unzip blocks-08-04-19.zip

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
