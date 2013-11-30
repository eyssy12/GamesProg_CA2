#ifndef INVENTORY_H
#define INVENTORY_H

#include <vector>
#include "Item.h"

using std::vector;

class Inventory
{
public:
	Inventory();
	Inventory(int inventorySize);

	//methods
	int getInventorySize();
	int getItemCount();

	void displayItemsByType(Item::ItemType itemType);
	void displayAllItems();
	void addItemToInventory(Item newItem);
	void removeItemFromInventory(int index);

private:

	// set the size to 10 using the inventorySize variable
	vector<Item> inventory;
};

#endif