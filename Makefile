.PHONY: all clean install uninstall

all: camcap

clean:
	rm -rf camcap *.o

camcap:
	gcc commitshot.c -o camcap -ljpeg

install:
	install ./camcap /usr/local/bin

uninstall:
	rm -rf /usr/local/bin/commitshot
