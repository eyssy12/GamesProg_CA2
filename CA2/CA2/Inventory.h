#ifndef INVENTORY_H
#define INVENTORY_H

#include <vector>
#include "Item.h"
#include "Weapon.h"
#include "HealingKit.h"

using std::vector;

class Inventory
{
public:
	Inventory();

	//methods
	int getInventorySize();
	vector<Weapon> getWeapons();
	vector<HealingKit> getHealingKits();

	void displayAllItems();
	void addWeapon(const Weapon& newWeapon);
	void addHealingKit(const HealingKit& newHealingKit);
	void removeHealingKit(const int& locations);
	void removeWeapon(const int& locations);

private:

	vector<Weapon> weapons;
	vector<HealingKit> healingKits;
};

#endif