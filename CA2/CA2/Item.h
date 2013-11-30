#ifndef ITEM_H
#define ITEM_H

#include <string>


class Item
{

public:

	enum Reusability
	{
		YES = true, NO = false
	};

	enum ItemType
	{
		WEAPON, HEALING
	};

	Item();
	Item(std::string name, ItemType itemType, Reusability isReusable);

	void setName(std::string name);
	void setItemType(ItemType itemType);
	void setReusability(Reusability newState);

	virtual ItemType getItemType();
	virtual std::string getItemName();

	virtual std::string getItemTypeStr();
	virtual std::string getReusabilityStr();

	Reusability isItemReusable();
	void printAllItemDetails();

private:

	std::string name;
	ItemType itemType;
	Reusability isReusable;

};

#endif