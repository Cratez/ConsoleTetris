#include <Windows.h>
#include <memory>
#include <iostream>
#include <vector>
#include "console_graphics.h"
#include <math.h>
#include "Tetris.h"

/*
TODO. Array of bools for gameboard should be "square" object. Should contain info about color and "in use"

Need to restrict play area to like... 15 wide center area. Modifiable? Sides should be filled in with color. Maybe in a pattern. 

Next piece preview?

ability for lines to erase

etc...

*/

using namespace std;


CONSOLE_SIZE GetConsoleSize() {
	CONSOLE_SCREEN_BUFFER_INFO csb;
	short col, row;

	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csb);
	col = csb.srWindow.Right + 1;
	row = csb.srWindow.Bottom + 1;

	return CONSOLE_SIZE( col, row );
}

int main(int argc, char** argv) {
	int RV = ERROR_SUCCESS;
	CONSOLE_SIZE conoleSize = GetConsoleSize();
	Tetris game(conoleSize);

	RV = game.Start();

	return RV;
}


