#include "Item.h"

std::unordered_map<ItemTypes, int> Item::maxUsePerItem = 
{
	{ItemTypes::Default, 1}
};

Item::Item(ItemTypes itemType)
{
	itemType = itemType;
	usesLeft = maxUsePerItem[itemType];
}

int Item::GetUsesLeft()
{
	return usesLeft;
}

ItemTypes Item::GetItemType()
{
	return itemType;
}

bool Item::DecrementUses()
{
	usesLeft--;
	if (usesLeft < 0)
	{
		return false;
	}
	return true;
}
