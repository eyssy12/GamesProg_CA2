
#ifndef WEAPON_H
#define WEAPON_H

#include <string>
#include "Item.h"

using std::string;

class Weapon : public Item
{

public:
	Weapon();
	Weapon(string name, ItemType itemType, Reusability isReusable, int damageRate);

	int getDamageRate();
	void setDamageRate(int newDmgRate);

	void printAllItemDetails();

private:
	int damageRate;

};

#endif //WEAPON_H

