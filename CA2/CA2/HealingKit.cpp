
#include <iostream>

#include "Item.h"
#include "HealingKit.h"

using namespace std;

HealingKit::HealingKit()
{

}

HealingKit::HealingKit(string nName, ItemType nItemType, Reusability nIsReusable, int nHealingRate)
: Item(nName, nItemType, nIsReusable)
{

	healingRate = nHealingRate;
}

int HealingKit::getHealingRate()
{
	return healingRate;
}

void HealingKit::setHealingRate(int newHealingRate)
{
	healingRate = newHealingRate;
}

void HealingKit::printAllItemDetails()
{
	Item::printAllItemDetails();
	cout << "Healing rate: " << healingRate << endl;
	cout << endl;
}
