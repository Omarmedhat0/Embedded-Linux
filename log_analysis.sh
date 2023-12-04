#!/bin/bash
whoami
hostname
cat app.log| grep "Error"| cut -b 28- app.log | sort | uniq -c 
