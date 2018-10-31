#pragma once
#include <vector>

class GameBoard {
	std::vector< std::vector<bool> > mGrid;
	CONSOLE_SIZE mConsoleSize;

public:
	GameBoard(CONSOLE_SIZE consoleSize) :
		mConsoleSize(consoleSize)
	{

	}

	unsigned GetWidth() {
		return mConsoleSize.Width;
	}

	unsigned GetHeight() {
		return mConsoleSize.Height;
	}
};
