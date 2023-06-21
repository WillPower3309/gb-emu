#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "gameboy.h"

struct gameboy gameboyCreate(char *romPath) {
	return (struct gameboy) {
		.cartridge = createCartridge(romPath),
	};
}
