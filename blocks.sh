#!/bin/bash


function bootstrap() {
printf "We will start kill DogeCash services before downloading the Bootstrap.\n"

killall dogecashd
sleep 2
systemctl stop DogeCash.service

printf "Now we need to install MegaTools.\n"
sudo apt-get install -y megatools unzip

megadl 'https://mega.nz/#!tMJnQI5K!MJV5v5qkt_VGUau8cvSed8QsfD85ISblHdZloEyzxAk'
sleep 2
unzip blocks-02-04-19.zip -d /root/.dogecash

echo -e "Bootstrap Applied."

read -n 1 -s -r -p "Press any key to continue \n"

}


function restart_mn() {

systemctl start DogeCash.service
sleep 15
systemctl enable DogeCash.service

printf "DogeNode restarted. \n"
read -n 1 -s -r -p "Press any key to continue"

}

##MAIN##

clear
bootstrap
restart_mn
