
#include <iostream>

#include "Utility.h"
#include "HealingKit.h"
#include "Item.h"
#include "Weapon.h"
#include "Generics.h"
#include "Enemy.h"
#include "Player.h"
#include "Map.h"

using namespace std;

int const HP_INCREASE_BASE_RATE = 100;
int const EXP_INCREASE_BASE_RATE = 10;

Player::Player(string nName, Weapon nWeapon)
{
	name = nName;
	weapon = nWeapon;

	lvl = 1;
	maxHp = lvl*HP_INCREASE_BASE_RATE;
	hp = maxHp;
	currExp = 0;
	expToNextLvl = lvl * lvl * EXP_INCREASE_BASE_RATE;
}

Player::Player(string nName, Weapon nWeapon, Inventory startInventory)
{
	name = nName;
	weapon = nWeapon;
	playerInventory = startInventory;

	lvl = 1;
	maxHp = lvl*HP_INCREASE_BASE_RATE;
	hp = maxHp;
	currExp = 0;
	expToNextLvl = lvl * lvl * EXP_INCREASE_BASE_RATE;
}

Player::Player(string nName, int nExp, int nExpToNextLevel, int nLvl, Weapon nWeapon)
{
	name = nName;
	maxHp = lvl*HP_INCREASE_BASE_RATE;
	hp = maxHp;
	currExp = nExp;
	expToNextLvl = nExpToNextLevel;
	lvl = nLvl;
	weapon = nWeapon;
}

string Player::getName()
{
	return name;
}

int Player::getHP()
{
	return hp;
}

int Player::getLevel()
{
	return lvl;
}

int Player::getExperience()
{
	return currExp;
}

Weapon Player::getWeapon()
{
	return weapon;
}

void Player::setHP(int newHp)
{
	hp = newHp;
}

bool Player::useHealingPotion()
{
	if (playerInventory.getHealingKits().size() == 0)
	{
		return false;
	}

	HealingKit temp = playerInventory.getHealingKits().at(0);

	// we increase the health of the player if its below the max hp allowed
	if (hp < maxHp)
	{
		hp += temp.getHealingRate(); //add more health to the player
	}
	playerInventory.removeHealingKit(0); //remove used healingkit from the inventory

	return true;
}

void Player::showPlayerInventory()
{
	playerInventory.displayAllItems();
}

void Player::showPlayerStats()
{
	cout << endl;
	cout << endl;
	cout << "------------------" << endl;
	cout << "Name: " << name << endl;
	cout << "Level: " << lvl << endl;
	cout << "Hit Points: " << hp << endl;
	cout << "Experience: " << currExp << endl;
	cout << "Next level: " << expToNextLvl << " Exp needed" << endl;
	cout << "Current weapon: " << weapon.getItemName() << endl;
	cout << "------------------" << endl;
	cout << endl;
}

