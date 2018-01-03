#!/data/data/com.termux/usr/bin/bash

apt update && apt upgrade
apt install clang make
make && make clean
