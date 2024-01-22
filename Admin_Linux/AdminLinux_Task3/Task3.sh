#!/bin/bash
cd ~
if test -f .bashrc; then
	if grep -q "HELLO=$HOSTNAME" ~/.bashrc; then
	:
	else
	echo export HELLO=$HOSTNAME >> ~/.bashrc
	fi
	if grep -q "LOCAL=$(whoami)" ~/.bashrc;then 
	:
	else
	echo LOCAL=$(whoami) >> ~/.bashrc
	fi
else
	echo ".bashtc file not exist"
fi
gnome-terminal
