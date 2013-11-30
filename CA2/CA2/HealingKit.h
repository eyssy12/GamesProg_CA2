
#ifndef HEALINGKIT_H
#define HEALINGKIT_H

#include <string>
#include "Item.h"

class HealingKit : public Item
{

public:

	HealingKit();
	HealingKit(std::string name, ItemType itemType, Reusability isReusable, int healingRate);

	virtual int getHealingRate();
	virtual void setHealingRate(int newHealingRate);

	void printAllItemDetails();

private:
	int healingRate;
};

#endif