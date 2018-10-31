#include "Tetris.h"

Tetris::Tetris(CONSOLE_SIZE gridsize) :
	//mGridsize(gridsize),
	mStatusCode(ERROR_SUCCESS),
	mGameActive(true),
	mGameboard(gridsize),
	mIOHandler(IOHandler::Instance())
{
	//draw gameboard...
	drawBlock(0, 0, 1, gridsize.Width,BLUE);
	drawBlock(gridsize.Height-1, 0, 1, gridsize.Width, BLUE);
	drawBlock(0, 0, gridsize.Height, 2, BLUE);
	drawBlock(0, gridsize.Width-2, gridsize.Height, 2, BLUE);
}

int Tetris::Start() {
	KEY_STROKE currentKey;

	//while playing game...
	while (mGameActive) {
		// we get a new block each time...
		Block currentBlock(mGameboard);

		//while the block hasnt hit the bottom...
		while (currentBlock.GetIsActive()) {

			//get input if any...
			currentKey = mIOHandler.GetKeyPress();
			currentBlock.Update(currentKey);

			//draw that super pretty block
			currentBlock.Draw();
			Sleep(100);
		}
	}
	return mStatusCode;
}