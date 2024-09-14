#pragma once
#include "InventorySource.h"
#include "NetworkItemStackDescriptor.h"

class InventoryAction {
public:
	InventorySource inventorySource; // 0x0
	int slot; // 0xC
	NetworkItemStackDescriptor fromItemDescripter; // 0x10
	NetworkItemStackDescriptor toItemDescripter; // 0x70
	ItemStack from; // 0xD0
	ItemStack to; // 0x170
public:
	InventoryAction() = default;
	// bu cua nuvola tai t dell hieuu gi :)
	InventoryAction(InventorySource source, int slot, const ItemStack& fromItem, const ItemStack& toItem) {
		this->inventorySource = source;
		this->slot = slot;
		NetworkItemStackDescriptor fromDescriptor(fromItem);
		NetworkItemStackDescriptor toDescriptor(toItem);
		memcpy(&this->fromItemDescripter, &fromDescriptor, sizeof(ItemStack));
		memcpy(&this->toItemDescripter, &toDescriptor, sizeof(ItemStack));
		memcpy(&this->from, &from, sizeof(ItemStack));
		memcpy(&this->to, &to, sizeof(ItemStack));
	}
};
