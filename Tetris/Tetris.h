#include <Windows.h>
#include "console_graphics.h"
#include "Block.h"
#include "GameBoard.h"
#include "Misc.h"
#include "IOHandler.h"

#pragma once
#define PLAY_AREA_WIDTH 20;

class Tetris {
private:
	//CONSOLE_SIZE mGridsize;
	GameBoard mGameboard;
	IOHandler& mIOHandler;
	int mStatusCode;
	bool mGameActive;

public:
	Tetris(CONSOLE_SIZE gridsize);
	int Start();
};