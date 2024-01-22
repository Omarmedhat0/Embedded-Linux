#!/bin/bash
mkdir ~/myDirectory
mkdir ~/myDirectory/secondDirectory
cd ~/myDirectory/secondDirectory
touch myNotePaper
cp myNotePaper ../
cd ..
mv myNotePaper myOldNotePaper

