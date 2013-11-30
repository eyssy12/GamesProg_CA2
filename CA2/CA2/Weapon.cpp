
#include <iostream>

#include "Weapon.h"
#include "Item.h"

using namespace std;

Weapon::Weapon()
{
	
}

Weapon::Weapon(string nName, ItemType nItemType, Reusability nIsReusable, int nDamageRate)
{
	//name = nName;
	//itemType = nItemType;
	//isReusable = nIsReusable;
	//damageRate = nDamageRate;
}

int Weapon::getDamageRate()
{
	return damageRate;
}

void Weapon::setDamageRate(int newDmgRate)
{
	damageRate = newDmgRate;
}

void Weapon::printAllItemDetails()
{
	cout << "Name: " << getItemName() << endl
		<< "Type: " << getItemType() << endl
		<< "Is reusable: " << isItemReusable() << endl
		<< "Damage rate: " << damageRate << endl;
}
