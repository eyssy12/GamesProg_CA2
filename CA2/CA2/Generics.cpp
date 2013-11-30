
#include <string>

#include "Enemy.h"

using namespace std;

Enemy createEnemy(const Enemy::EnemyType& enemyType)
{
	Weapon weapon;
	Enemy enemy;

	if (enemyType == Enemy::EnemyType::WEAK)
	{
		weapon.setItemType(Item::ItemType::WEAPON);
		weapon.setName("Knife");
		weapon.setReusability(Item::Reusability::YES);
		weapon.setDamageRate(9);

		//EnemyType nEnemyType, string nName, int nHp, int nLvl, Weapon nWeapon
		enemy.setEnemyType(Enemy::EnemyType::WEAK);
		enemy.setName("Recruit");
		enemy.setHP(50);
		enemy.setLevel(1);
		enemy.setWeapon(weapon);

	}
	else if (enemyType == Enemy::EnemyType::MEDIUM)
	{
		weapon.setItemType(Item::ItemType::WEAPON);
		weapon.setName("Electrical batton");
		weapon.setReusability(Item::Reusability::YES);
		weapon.setDamageRate(15);

		enemy.setEnemyType(Enemy::EnemyType::MEDIUM);
		enemy.setName("Sergeant");
		enemy.setHP(100);
		enemy.setLevel(2);
		enemy.setWeapon(weapon);
	}
	else if (enemyType == Enemy::EnemyType::STRONG)
	{
		weapon.setItemType(Item::ItemType::WEAPON);
		weapon.setName("Katana");
		weapon.setReusability(Item::Reusability::YES);
		weapon.setDamageRate(20);

		enemy.setEnemyType(Enemy::EnemyType::STRONG);
		enemy.setName("Captain");
		enemy.setHP(130);
		enemy.setLevel(3);
		enemy.setWeapon(weapon);
	}

	return enemy;
}
