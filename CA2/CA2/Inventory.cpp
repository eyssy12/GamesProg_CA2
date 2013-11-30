#include <iostream>

#include "Inventory.h"
#include "Utility.h"

using namespace std;

vector<Weapon>::iterator weaponIter;
vector<HealingKit>::iterator healingIter;

Inventory::Inventory()
{
}

vector<Weapon> Inventory::getWeapons()
{
	return weapons;
}

vector<HealingKit> Inventory::getHealingKits()
{
	return healingKits;
}

void Inventory::displayAllItems()
{
	if (weapons.size() == 0 && healingKits.size() == 0)
	{
		printMessageWithBorders("Inventory is empty.");
	}
	else
	{
		for (weaponIter = weapons.begin(); weaponIter != weapons.end(); weaponIter++)
		{
			// instead of Healing there will be name, weapon etc...
			cout << weaponIter->getItemName() << endl;
		}

		for (healingIter = healingKits.begin(); healingIter != healingKits.end(); healingIter++)
		{
			cout << healingIter->getItemName() << endl;
		}
	}

	cout << endl;
}

void Inventory::removeHealingKit(const int& location)
{
	healingKits.erase(healingKits.begin() + location);
}

void Inventory::removeWeapon(const int& location)
{
	weapons.erase(weapons.begin() + location);
}

void Inventory::addWeapon(const Weapon& newWeapon)
{
	weapons.push_back(newWeapon);
}

void Inventory::addHealingKit(const HealingKit& newHealingKit)
{
	healingKits.push_back(newHealingKit);
}
