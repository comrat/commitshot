.PHONY: all clean install uninstall

all: commitshot

clean:
		rm -rf commitshot *.o

capture.o: capture.c
		gcc -c capture.c -o capture.o

daemon.o: daemon.c
		gcc -c daemon.c -o daemon.o

history.o: history.c
		gcc -c history.c -o history.o

commitshot: daemon.o capture.o history.o
		gcc -o commitshot daemon.o capture.o history.o -ljpeg

install:
		install ./commitshot /usr/local/bin

uninstall:
		rm -rf /usr/local/bin/commitshot
