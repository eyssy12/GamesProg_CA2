
#include <string>


#include "Enemy.h"
#include "Weapon.h"

using namespace std;

Enemy::Enemy()
{
	enemyType = Enemy::EnemyType::WEAK;
	name = "";
	hp = 0;
	lvl = 0;
}

Enemy::Enemy(EnemyType nEnemyType, string nName, int nHp, int nLvl, Weapon nWeapon)
{
	enemyType = nEnemyType;
	name = nName;
	hp = nHp;
	lvl = nLvl;
	weapon = nWeapon;
};

Enemy::EnemyType Enemy::getEnemyType()
{
	return enemyType;
}

int Enemy::getHP()
{
	return hp;
}

Weapon Enemy::getWeapon()
{
	return weapon;
}

void Enemy::setName(string nName)
{
	name = nName;
}

void Enemy::setHP(int nHp)
{
	hp = nHp;
}

void Enemy::setLevel(int nLvl)
{
	lvl = nLvl;
}

void Enemy::setWeapon(Weapon nWeapon)
{
	weapon = nWeapon;
}

void Enemy::setEnemyType(Enemy::EnemyType nEnemyType)
{
	enemyType = nEnemyType;
}

