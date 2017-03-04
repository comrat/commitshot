.PHONY: all clean install uninstall

all: commitshot

clean:
	rm -rf commitshot *.o

commitshot:
	gcc commitshot.c -o commitshot -ljpeg

install:
	install ./commitshot /usr/local/bin

uninstall:
	rm -rf /usr/local/bin/commitshot
