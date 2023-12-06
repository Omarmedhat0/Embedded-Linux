#!/bin/bash
 whoami
hostname
cat app.log| grep "Error"| cut -b 28- | sort | uniq -c 
