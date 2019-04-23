#!/bin/bash

GREEN='\033[0;32m'
NC='\033[0m'
function bootstrap() {
printf "We will start kill DogeCash services before downloading the Bootstrap.\n"

killall dogecashd
sleep 5
systemctl stop DogeCash.service

printf "Now we need to install MegaTools.\n"
sudo apt-get install -y megatools p7zip-full

cd /root/.dogecash
megadl 'https://mega.nz/#!BcoWEIjK!s1QHoXIQH3NrLWwleOaXcWbwgdF7HbUGt_ALdi94iPI'
sleep 10
echo -e "${GREEN}Now downloading and installing Bootstrap${NC}"
7z e blocks-21-04-19.7z

echo -e "${GREEN}Bootstrap Applied.${NC}"

}


function restart_mn() {
systemctl stop DogeCash.service
sleep 10
systemctl start DogeCash.service
sleep 11
systemctl enable DogeCash.service
sleep 11

printf "${GREEN}DogeNode restarted.${NC} \n"
echo -e " "
systemctl status DogeCash.service

}

##MAIN##

clear
bootstrap
restart_mn
