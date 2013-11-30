#ifndef PLAYER_H
#define PLAYER_H

#include <string>

#include "Weapon.h"
#include "Inventory.h"

using std::string;

class Player
{
public:

	// constructor
	Player(string name, int hp, int exp, int level, Weapon weapon, Inventory playerInventory);

	// getters
	string getName();
	int getHP();
	int getExperience();
	int getLevel();
	Weapon getWeapon();

	// setters
	void setName(string name);
	void setHP(int hp);
	void setExp(int exp);
	void setLevel(int lvl);
	void setWeapon(Weapon newWeapon);

	// other methods
	void showPlayerInventory();

private:

	//variables
	string name;
	int hp;
	int exp;
	int lvl;
	Weapon weapon;
	Inventory playerInventory; //player will start with a basic inventory of 5 medpacks or so

};

#endif