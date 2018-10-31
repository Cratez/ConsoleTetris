#pragma once

#include "Misc.h"
#include "GameBoard.h"
#include <Windows.h>


typedef bool BLOCK_DATA_TYPE;
class Block {
private:
	BLOCK_DATA_TYPE mGrid[BLOCK_SIZE][BLOCK_SIZE];
	COORD mPosition;
	GameBoard& mGameBoard;
	bool mIsActive;
	COLOR mColor;


	void initialize();
	void moveHorizontal(KEY_STROKE direction);
	void Rotate();

public:
	Block(GameBoard& gameboard);

	int Update(KEY_STROKE input);
	void Draw();
	bool GetIsActive();

};