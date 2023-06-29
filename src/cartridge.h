#ifndef _CARTRIDGE_H
#define _CARTRIDGE_H

#include <stdbool.h>

enum cartridgeType {
	ROM = 0x0,
	ROM_MBC1 = 0x1,
	ROM_MBC1_RAM = 0x2,
	ROM_MBC1_RAM_BATTERY = 0x3,
	ROM_MBC2 = 0x5,
	ROM_MBC2_BATTERY = 0x6,
	ROM_RAM = 0x8,
	ROM_RAM_BATTERY = 0x9,
	ROM_MMM01 = 0xB,
	ROM_MMM01_SRAM = 0xC,
	ROM_MMM01_SRAM_BATTERY = 0xD,
	ROM_MBC3_TIMER_BATTERY = 0xF,
	ROM_MBC3_TIMER_RAM_BATTERY = 0x10,
	ROM_MBC3 = 0x11,
	ROM_MBC3_RAM = 0x12,
	ROM_MBC3_RAM_BATTERY = 0x13,
	ROM_MBC5 = 0x19,
	ROM_MBC5_RAM = 0x1A,
	ROM_MBC5_RAM_BATTERY = 0x1B,
	ROM_MBC5_RUMBLE = 0x1B,
	ROM_MBC5_RUMBLE_SRAM = 0x1D,
	ROM_MBC5_RUMBLE_SRAM_BATTERY = 0x1E,
	POCKETCAMERA = 0x1F,
	BANDAITAMA5 = 0xFD,
	HUDSONHUC3 = 0xFE,
	HUDSONHUC1 = 0xFF,
};

struct cartridge {
	enum cartridgeType type;
};

struct cartridge createCartridge(char *romPath);

#endif
