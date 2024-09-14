#pragma once
#include "../../Utils/MemoryUtils.h"
#include "Item.h"

class ItemStackBase {
public:
	BUILD_ACCESS(this, Item**, item, 0x8);
	//BUILD_ACCESS(this, CompoundTag*, compoundtag, 0x10);
	//BUILD_ACCESS(this, Block*, block, 0x18);
	BUILD_ACCESS(this, int16_t, uses, 0x20);
	BUILD_ACCESS(this, int8_t, stackCount, 0x22);
public:
	inline Item* getItemPtr() {
		if (this->item == NULL) return nullptr;
		return *this->item;
	}

	int getEnchantLevel(int enchantId) {
		using func_t = int (__thiscall*)(int, ItemStackBase*);
		static func_t func = (func_t)findSig(Sigs::enchantutils::getenchantlevel);
		return func(enchantId, this);
	}
};
