#pragma once
#include "PathStruct.h"

class TextureData {
private:
	char pad_0x0[0x18]; // 0x0
public:
	PathStruct* ptrToPath; // 0x18
};