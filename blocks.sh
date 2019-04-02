#!/bin/bash


function bootstrap() {
echo -e "We will start kill DogeCash services before downloading the Bootstrap."

killall dogecashd
sleep 2
systemctl stop DogeCash.service
cd /root/.dogecash
rm -rf blocks

echo -e "Now we need to install MegaTools."
sudo apt-get install -y megatools unzip

megadl 'https://mega.nz/#!pAJzkYZR!fx7gDaNyaf19V_Xt4da3T0ifevmUgKGJmbRqc7lMLVs'
progress-bar 100
unzip blocks_01.04.19.zip
cp /blocks /home/.dogecash

echo -e "Bootstrap Applied."

read -n 1 -s -r -p "Press any key to continue"

}


function restart_mn() {

systemctl start DogeCash.service
sleep 15
systemctl enable DogeCash.service

echo -e "DogeNode restarted."
read -n 1 -s -r -p "Press any key to continue"

}

progress-bar() {
  local duration=${1}


    already_done() { for ((done=0; done<$elapsed; done++)); do printf "▇"; done }
    remaining() { for ((remain=$elapsed; remain<$duration; remain++)); do printf " "; done }
    percentage() { printf "| %s%%" $(( (($elapsed)*100)/($duration)*100/100 )); }
    clean_line() { printf "\r"; }

  for (( elapsed=1; elapsed<=$duration; elapsed++ )); do
      already_done; remaining; percentage
      sleep 1
      clean_line
  done
  clean_line
}

##MAIN##

clear
bootstrap
restart_mn
