#ifndef PLAYER_H
#define PLAYER_H

#include <string>

#include "Weapon.h"
#include "Inventory.h"
#include "Enemy.h"

class Player
{
public:

	// constructors
	Player(std::string name, Weapon weapon);
	Player(std::string name, Weapon weapon, Inventory startInventory);
	Player(std::string name, int exp, int expToNextLvl, int level, Weapon weapon);

	// getters
	std::string getName();
	int getHP();
	int getExperience();
	int getExperienceToNextLevel();
	int getLevel();
	Weapon getWeapon();

	// setters
	void setName(std::string name);
	void setHP(int hp);
	void setExp(int exp);
	void setLevel(int lvl);
	void setWeapon(Weapon newWeapon);

	void addItemToPlayerInventory(const Item& newItem);
	bool useHealingPotion();

	// other methods
	void showPlayerInventory();
	void showPlayerStats();

private:

	// variables
	std::string name;
	int hp;
	int maxHp;
	int currExp;
	int expToNextLvl;
	int lvl;
	Weapon weapon;
	Inventory playerInventory; //player will start with a basic inventory of 5 medpacks or so

};

#endif