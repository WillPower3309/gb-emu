#ifndef _GAMEBOY_H
#define _GAMEBOY_H

#include "cartridge.h"

struct gameboy {
	struct cartridge cartridge;
};

struct gameboy gameboyCreate(char *romPath);

#endif
