#!/bin/bash


function bootstrap() {
echo -e "We will start kill DogeCash services before downloading the Bootstrap.\n"

killall dogecashd
sleep 2
systemctl stop DogeCash.service
cd /root/.dogecash
rm -rf blocks

echo -e "Now we need to install MegaTools."
sudo apt-get install -y megatools unzip
sleep 2
clear
megadl 'https://mega.nz/#!tMJnQI5K!MJV5v5qkt_VGUau8cvSed8QsfD85ISblHdZloEyzxAk'
unzip blocks_01.04.19.zip
cp /blocks /home/.dogecash

echo -e "Bootstrap Applied.\n"

read -n 1 -s -r -p "Press any key to continue\n"

}


function restart_mn() {

systemctl start DogeCash.service
sleep 15
systemctl enable DogeCash.service

echo -e "DogeNode restarted."
read -n 1 -s -r -p "Press any key to continue\n"

}

##MAIN##

clear
bootstrap
restart_mn
