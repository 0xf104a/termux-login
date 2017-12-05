CC=g++
CFLAGS=-c -Wall
LDFLAGS=
SOURCES=login.cpp crypto/sha512/sha512.cpp getpass.cpp cutil/strutil.c checkuser.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=login
BIN=/data/data/com.termux/files/usr/bin
FSROOT=/data/data/com.termux/files
all:adduser login passwd post clean

adduser:
	cd adduser && make
	cd ..

login:
	cd login && make
	cd ..

passwd:
	cd passwd && make
	cd ..
post:
	sh scripts/post-install.sh

clean:
	rm -rf .*.swp
	cd passwd && make clean
	cd ..
	cd login && make clean
	cd ..
	cd adduser && make clean
