CC=g++
CFLAGS=-c -Wall
LDFLAGS=
SOURCES=passwd.cpp crypto/sha512/sha512.cpp getpass.cpp cutil/strutil.c checkuser.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=passwd
BIN=/data/data/com.termux/files/usr/bin
FSROOT=/data/data/com.termux/files
all:compile install clean

compile: $(SOURCES) $(EXECUTABLE)

install: compile
	cp $(EXECUTABLE) $(BIN)/passwd
clean:
	rm -f *.o
	rm -f .*.swp
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@
