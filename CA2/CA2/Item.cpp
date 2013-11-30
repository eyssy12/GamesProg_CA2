#include <iostream>

#include "Item.h"

using namespace std;

Item::Item()
{
	name = "";
	itemType = ItemType::HEALING;
	isReusable = Reusability::NO;
}

Item::Item(string nName, ItemType nItemType, Reusability nIsReusable)
{
	name = nName;
	itemType = nItemType;
	isReusable = nIsReusable;
}

void Item::setName(string newName)
{
	name = newName;
}

void Item::setItemType(Item::ItemType nItemType)
{
	itemType = nItemType;
}

void Item::setReusability(Item::Reusability newState)
{
	isReusable = newState;
}

Item::ItemType Item::getItemType()
{
	return itemType;
}

string Item::getItemName()
{
	return name;
}

Item::Reusability Item::isItemReusable()
{
	return isReusable;
}

void Item::printAllItemDetails()
{
	string itemTypeStr = getItemTypeStr();
	string reusabilityStr = getReusabilityStr();


	cout << "Name: " << name << endl
		<< "Type: " << itemTypeStr << endl
		<< "Is reusable: " << reusabilityStr << endl;
}

string Item::getItemTypeStr()
{
	if (itemType == ItemType::WEAPON)
		return  "Weapon";
	else if (itemType == ItemType::HEALING)
		return  "Healing";
	else
		return "";

}

string Item::getReusabilityStr()
{
	if (isReusable == Reusability::YES)
		return "Yes";
	else if (isReusable == Reusability::NO)
		return "No";
	else
		return "";
}
