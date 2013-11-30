#include <iostream>

#include "Item.h"

using namespace std;

Item::Item()
{

}

Item::Item(string nName, ItemType nItemType, Reusability nIsReusable)
{
	name = nName;
	itemType = nItemType;
	isReusable = nIsReusable;
}

Item::ItemType Item::getItemType()
{
	return itemType;
}


string Item::getItemName()
{
	return name;
}

bool Item::isItemReusable()
{
	return isReusable;
}

void Item::printAllItemDetails()
{
	cout << "Name: " << name << endl
		<< "Type: " << itemType << endl
		<< "Is reusable: " << isReusable << endl;
}