CC=gcc
CFLAGS=-Wall -O2 -std=gnu99
OBJECTS=src/cartridge.c src/gameboy.c src/main.c

main: $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o gb

