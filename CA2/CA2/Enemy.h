#ifndef ENEMY_H
#define ENEMY_H

#include <string>
#include "Weapon.h"


class Enemy
{
public:

	enum EnemyType
	{
		WEAK, MEDIUM, STRONG
	};

	Enemy();
	Enemy(EnemyType enemyType, std::string name, int hp, int lvl, Weapon weapon);

	// getters
	std::string getName();
	int getHP();
	int getLevel();
	Weapon getWeapon();
	EnemyType getEnemyType();

	// setters
	void setName(std::string name);
	void setHP(int hp);
	void setLevel(int lvl);
	void setWeapon(Weapon newWeapon);
	void setEnemyType(EnemyType enemyType);

private:

	//variables
	EnemyType enemyType;
	std::string name;
	int hp;
	int lvl;
	Weapon weapon;
};



#endif
