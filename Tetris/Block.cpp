#include "Block.h"
#include "console_graphics.h"


void Block::initialize() {
	mGrid[0][0] = true;
	mGrid[0][1] = true;
	mGrid[0][2] = true;
	mGrid[0][3] = true;
}

void Block::moveHorizontal(KEY_STROKE direction) {

	switch (direction) {
	case KEY_STROKE::LEFT:
		if (mPosition.X - 1 >= 0)
			mPosition.X -= 1;
		break;

	case KEY_STROKE::RIGHT:
		if (mPosition.X + 1 < mGameBoard.GetWidth() - 1)
			mPosition.X += 1;
		break;

	default:
		MessageBox(NULL, "You are really dumb!", "Accept it as fact", MB_OK);
		break;
	}

}

void Block::Rotate() {
	// In-place matrix transposition
	for (int n = 0; n <= BLOCK_SIZE - 2; n++) {
		for (int m = n + 1; m <= BLOCK_SIZE - 1; m++) {
			BLOCK_DATA_TYPE temp = mGrid[n][m];
			mGrid[n][m] = mGrid[m][n];
			mGrid[m][n] = temp;
		}
	}
}


Block::Block(GameBoard& gameboard) :
	mGameBoard(gameboard),
	mIsActive(true)
{

	mPosition = COORD{ 0 , 0 };
	mColor = RED;

	//initialize the stoof
	for (int col = 0; col < BLOCK_SIZE; col++) {
		for (int row = 0; row < BLOCK_SIZE; row++) {
			mGrid[col][row] = false;
		}
	}

	//what are we....
	initialize();
}

int Block::Update(KEY_STROKE input) {

	switch (input) {
		//move right
	case KEY_STROKE::RIGHT:
		moveHorizontal(KEY_STROKE::RIGHT);
		break;
		//move left
	case KEY_STROKE::LEFT:
		moveHorizontal(KEY_STROKE::LEFT);
		break;
		//Rotate...clockwise?
	case KEY_STROKE::UP:
		Rotate();
		break;
		//move down 1
	case KEY_STROKE::DOWN:
		//not actually easy.... we need to err check if we CAN MOVE DOWN. Against GameBoard.
		mPosition.Y += 1;
		break;
		//DROP like a rock.
	case KEY_STROKE::SPACE:
		//not sure
		break;
	}

	return ERROR_SUCCESS;
}


void Block::Draw() {
	//how do draw ourselves...

	for (int col = 0; col < BLOCK_SIZE; col++) {
		for (int row = 0; row < BLOCK_SIZE; row++) {
			//if true... we draw
			if (mGrid[col][row]) {
				drawBlock(mPosition.X + col, mPosition.Y + row, 1, 1, mColor);
			}
		}
	}
}

bool Block::GetIsActive() {
	return mIsActive;
}