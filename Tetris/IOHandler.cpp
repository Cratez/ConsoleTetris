#include "IOHandler.h"
#include <Windows.h>

IOHandler* IOHandler::sInstance = nullptr;
std::mutex IOHandler::sLock;

IOHandler::IOHandler() {
	mIgnoreRight = false;
	mIgnoreLeft = false;
	mIgnoreUp = false;
	mIgnoreDown = false;
	mIgnoreSpace = false;
}

IOHandler::~IOHandler() {
	if (!sInstance) {
		delete sInstance;
	}
}

IOHandler& IOHandler::Instance() {
	sLock.lock();
	if (!sInstance) {
		sInstance = new IOHandler();
	}
	sLock.unlock();
	return *sInstance;
}

KEY_STROKE IOHandler::GetKeyPress() {
	DWORD NumInputs = 0;
	DWORD InputsRead = 0;
	INPUT_RECORD irInput;
	KEY_STROKE ks = KEY_STROKE::NONE;
	HANDLE hInput = GetStdHandle(STD_INPUT_HANDLE);

	//GetNumberOfConsoleInputEvents(hInput, &NumInputs);

	ReadConsoleInput(hInput, &irInput, 1, &InputsRead);

	//WORD keyCode = irInput.Event.KeyEvent.wVirtualKeyCode;

	//if (irInput.Event.KeyEvent.wRepeatCount == 1) {
	switch (irInput.Event.KeyEvent.wVirtualKeyCode)
	{
	case VK_ESCAPE:
		//Quit The Running Loop
		break;
	case VK_LEFT:
	case VK_NUMPAD4:
		//false
		//ignore will become true
		//we will return true, thereby setting the ksystroke
		if ((mIgnoreLeft = !mIgnoreLeft) ? mIgnoreLeft : mIgnoreLeft)
			ks = KEY_STROKE::LEFT;
		// move it left
		break;
	case VK_UP:
	case VK_NUMPAD8:
		if ((mIgnoreUp = !mIgnoreUp) ? mIgnoreUp : mIgnoreUp)
			ks = KEY_STROKE::UP;
		// move it up
		break;
	case VK_RIGHT:
	case VK_NUMPAD6:
		if ((mIgnoreRight = !mIgnoreRight) ? mIgnoreRight : mIgnoreRight)
			ks = KEY_STROKE::RIGHT;
		// move it right
		break;
	case VK_DOWN:
	case VK_NUMPAD2:
		if ((mIgnoreDown = !mIgnoreDown) ? mIgnoreDown : mIgnoreDown)
			ks = KEY_STROKE::DOWN;
		// move it down
		break;

	case VK_SPACE:
		if ((mIgnoreSpace = !mIgnoreSpace) ? mIgnoreSpace : mIgnoreSpace)
			ks = KEY_STROKE::SPACE;
		break;
	}

	//flush any inputs
	if (InputsRead > 0) {
		FlushConsoleInputBuffer(hInput);
	}

	return ks;
}


