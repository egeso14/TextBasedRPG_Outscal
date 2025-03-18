#pragma once
#include "ItemTypes.h"
#include <unordered_map>

class Item {
private:
	static std::unordered_map<ItemTypes, int> maxUsePerItem;
	int usesLeft;
	ItemTypes itemType;
public:
	Item(ItemTypes itemType);

	int GetUsesLeft();
	ItemTypes GetItemType();
	bool DecrementUses();

};