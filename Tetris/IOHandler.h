#pragma once
#include <mutex>
#include "Misc.h"

class IOHandler {
private:
	bool mIgnoreRight;
	bool mIgnoreLeft;
	bool mIgnoreUp;
	bool mIgnoreDown;
	bool mIgnoreSpace;
	static IOHandler* sInstance;
	static std::mutex sLock;

	IOHandler();
	~IOHandler();
public:	

	static IOHandler& Instance();
	KEY_STROKE GetKeyPress();
};
