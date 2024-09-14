#pragma once
#include "Container.h"
#include "ItemStack.h"

class Inventory : public Container {
public:
	std::vector<ItemStack> stacks; //0x00E0

	int getEmptySlotFromContainer()
	{
		for (int currentSlot = 0; currentSlot < stacks.size(); currentSlot++)
		{
			const ItemStack& stack = this->stacks[currentSlot];
			if (!stack.item)
			{
				return currentSlot;
			}
		}
		return -1;
	}

	int getEmptySlotFromHotbar()
	{
		for (int inventoryRow = 3; inventoryRow > 0; inventoryRow--)
		{
			for (int currentSlot = 9 * inventoryRow; currentSlot < 9 * (inventoryRow + 1); currentSlot++)
			{
				const ItemStack& stack = this->stacks[currentSlot];
				if (!stack.item)
				{
					return currentSlot;
				}
			}
		}
		return -1;
	}
	/*void dropSlot(int slot) {
		// FillingContainer::dropSlot
		using drop_t = void(__fastcall*)(Inventory*, int, char);
		static drop_t func = reinterpret_cast<drop_t>(findSig(Sigs::Itemstack::Dropslot));
		if (func != 0)
			func( slot, 0);
	}*/
	void dropSlot(int slot) {
		using func_t = void(__thiscall*)(Inventory*,int, char, char);
		static func_t func = (func_t)findSig(Sigs::Itemstack::Dropslot);
		return func(this,slot, 0,0);
	}
};