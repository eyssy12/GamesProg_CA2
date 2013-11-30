/*
	Ill need:

	Item, Player, Enemy, Room classes

	1. Player class: name, hp, attack, weapon, inventroy

	2. Enemy: class, hp, attack, weapon, inventory, xp rate for killing

	3. Item: item name, damage rate, level required to use

	4. Room: name/id, size(2d array), items in the room, exits


*/

#include <iostream>
#include <string>

#include "Item.h"
#include "Map.h"
#include "Player.h"
#include "Weapon.h"


using namespace std;

int main()
{
	Item item("Dagger", Item::ItemType::WEAPON, Item::Reusability::YES);
	item.printAllItemDetails();
	//Weapon w1("Dagger", Item::ItemType::WEAPON, Item::Reusability::YES, 20);
	//w1.printAllItemDetails();

	//cout << w1.getItemName() << endl;

	return 0;
}