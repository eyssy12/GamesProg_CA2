#include <iostream>

#include "Inventory.h"

using namespace std;

vector<Item>::iterator inventoryIter;

Inventory::Inventory()
{
	inventory;
}

Inventory::Inventory(int initialSize)
{
	inventory; //set the initalsize
}

int Inventory::getInventorySize()
{
	return inventory.size();
}

int Inventory::getItemCount()
{
	int count = 0;

	for (inventoryIter = inventory.begin(); inventoryIter != inventory.end(); inventoryIter++)
	{
		

		//check if inventory contains an item
	}

	return count;
}

void Inventory::displayAllItems()
{
	for (inventoryIter = inventory.begin(); inventoryIter != inventory.end(); inventoryIter++)
	{
		// instead of Healing there will be name, weapon etc...
		cout << inventoryIter->getItemName() << endl;
	}
}

void Inventory::addItemToInventory(Item newItem)
{
	inventory.push_back(newItem);
}

void Inventory::removeItemFromInventory(int position)
{
	// check how to remove an item from a vector based on position
}