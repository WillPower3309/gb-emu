#include <stdio.h>
#include "gameboy.h"

int main(int argc, char *argv[]) {
	if (argc != 2) {
		// TODO: format message
		printf("Please specify an input ROM.\n");
		return 0;
	}

	struct gameboy gameboy = gameboyCreate(argv[1]);

	return 0;
}
