#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "cartridge.h"

bool isNintendoLogoPresent(uint8_t *cartridgeRom) {
	const int LOGO_START_ADDRESS = 0x104;
	const int LOGO_NUM_OPCODES = 48;

	//if (len(cartridgeRom) < LOGO_START_ADDRESS + LOGO_NUM_OPCODES) {
	//	return false;
	//}

	//const uint8_t nintendoGraphicOpcodes[LOGO_NUM_OPCODES] = {
	const uint8_t nintendoGraphicOpcodes[48] = {
		0xCE, 0xED, 0x66, 0x66, 0xCC, 0x0D, 0x00, 0x0B, 0x03, 0x73, 0x00, 0x83,
		0x00, 0x0C, 0x00, 0x0D, 0x00, 0x08, 0x11, 0x1F, 0x88, 0x89, 0x00, 0x0E,
		0xDC, 0xCC, 0x6E, 0xE6, 0xDD, 0xDD, 0xD9, 0x99, 0xBB, 0xBB, 0x67, 0x63,
		0x6E, 0x0E, 0xEC, 0xCC, 0xDD, 0xDC, 0x99, 0x9F, 0xBB, 0xB9, 0x33, 0x3E,
	};

	for (int i = 0; i < LOGO_NUM_OPCODES; i++) {
		if (cartridgeRom[i + LOGO_START_ADDRESS] != nintendoGraphicOpcodes[i]) {
			return false;
		}
	}

	return true;
}

struct cartridge createCartridge(char *romPath) {
	FILE *romFile = fopen(romPath, "rb");
	if (!romFile) {
		printf("Error! Rom %s does not exist.\n", romPath);
		exit(0);
	}

	const int ROM_BANK_SIZE = 0x4000;
	uint8_t memory[ROM_BANK_SIZE];

	// TODO: proper parameters
	if (fread(&memory[0], 1, ROM_BANK_SIZE, romFile) != ROM_BANK_SIZE) {
		printf("Error! Number of bytes read from rom differs from expected value.\n");
		exit(0);
	}
	fclose(romFile);

	if (!isNintendoLogoPresent(memory)) {
		printf("Error! Nintendo logo is not present, invalid ROM\n");
		exit(0);
	}

	for (int i = 0x134; i < 0x143; i++) {
	  printf("%c", memory[i]);
	}
	printf("\n");

	uint8_t flagCGB = memory[0x143];
	switch (flagCGB) {
		case 0x80:
			printf("Supports CGB functions, but also works on old gameboy\n");
			break;
		case 0xC0: // physically the same as 0x80
			printf("Supports CGB only\n");
			break;
		default:
			printf("Supports GB only\n");
			break; // TODO: stylistically should I do this?
	}

	// TODO: check 0x144 and 0x145 for licensee
	// TODO: check 0x146 for GB / SGB indicator

	uint8_t cartridgeTypeHex = memory[0x147]; // TODO: better name
	switch (cartridgeTypeHex) {
		case ROM:
			printf("Cartridge type: ROM\n");
			break;
		case ROM_MBC1:
			printf("Cartridge type: ROM_MBC1\n");
			break;
		case ROM_MBC1_RAM:
			printf("Cartridge type: ROM_MBC1_RAM\n");
			break;
		case ROM_MBC1_RAM_BATTERY:
			printf("Cartridge type: ROM_MBC1_RAM_BATTERY\n");
			break;
		case ROM_MBC2:
			printf("Cartridge type: ROM_MBC2\n");
			break;
		case ROM_MBC2_BATTERY:
			printf("Cartridge type: ROM_MBC2_BATTERY\n");
			break;
		default:
			printf("Cartridge type: %X\n", cartridgeTypeHex);
			break;
	}

	return (struct cartridge) {};
}
