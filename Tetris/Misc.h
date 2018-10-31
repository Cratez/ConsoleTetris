#pragma once

#define BLOCK_SIZE 4

typedef unsigned short COLOR;

enum KEY_STROKE { LEFT, RIGHT, UP, DOWN, SPACE, NONE };

struct CONSOLE_SIZE {
	const unsigned Width;
	const unsigned Height;

	CONSOLE_SIZE(unsigned width, unsigned height) :
		Width(width),
		Height(height) {	}
};
