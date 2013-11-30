
#include <iostream>

#include "Weapon.h"
#include "Item.h"

using namespace std;

Weapon::Weapon()
:Item("", ItemType::WEAPON, Reusability::NO)
{
	damageRate = 0;
}

Weapon::Weapon(string nName, ItemType nItemType, Reusability nIsReusable, int nDamageRate)
: Item(nName, nItemType, nIsReusable)
{

	damageRate = nDamageRate;
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
	Item::printAllItemDetails();
	cout << "Damage rate: " << damageRate << endl;
	cout << endl;
}
