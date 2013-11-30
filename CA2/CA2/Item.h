#ifndef ITEM_H
#define ITEM_H

#include <string>

using std::string;

class Item
{

public:

	enum Reusability
	{
		YES = 1, NO = 0
	};

	enum ItemType
	{
		WEAPON, HEALING
	};

	Item();
	Item(string name, ItemType itemType, Reusability isReusable);

	string setName(string name);
	bool setReusability(bool newState);

	ItemType getItemType();
	string getItemName();

	bool isItemReusable();
	void printAllItemDetails();

private:

	string name;
	ItemType itemType;
	bool isReusable;

};

#endif