.PHONY: all clean install uninstall

all: commitshot

clean:
		rm -rf commitshot *.o

capture.o: capture.c
		gcc -c capture.c -o capture.o

daemon.o: daemon.c
		gcc -c daemon.c -o daemon.o

commitshot: daemon.o capture.o
		gcc -o commitshot daemon.o capture.o -ljpeg

install:
		install ./commitshot /usr/local/bin

uninstall:
		rm -rf /usr/local/bin/hello
