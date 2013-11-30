
#include "Player.h"

using namespace std;


Player::Player(string name, int hp, int exp, int lvl, Weapon weapon, Inventory playerInventory)
{
	name = name;
	hp = hp;
	exp = exp;
	lvl = lvl;
	weapon = weapon;
	playerInventory = playerInventory;
}

string Player::getName()
{
	return name;
}

int Player::getHP()
{
	return hp;
}

int Player::getExperience()
{
	return exp;
}

Weapon Player::getWeapon()
{
	return weapon;
}

void Player::showPlayerInventory()
{
	playerInventory.displayAllItems();
}