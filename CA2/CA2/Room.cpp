
#include <iostream>
#include <string>

#include "Enemy.h"
#include "Room.h"
#include "Item.h"
#include "Entry.h"

using namespace std;

Room::Room()
{
	description = "";
	roomID = 0;
}

//std::string description, int roomID, vector<Entry> entryLocations
Room::Room(string nDescription, int nRoomID, vector<Entry> nEntryLocations)
{
	description = nDescription;
	roomID = nRoomID;
	entryLocations = nEntryLocations;
}

Room::Room(string nDescription, int nRoomID, vector<Entry> nEntryLocations, vector<Location> nEnemyLocations)
{
	description = nDescription;
	roomID = nRoomID;
	entryLocations = nEntryLocations;
	enemyLocations = nEnemyLocations;
}

Room::Room(string nDescription, int nRoomID, vector<Item> nRoomItems, vector<Entry> nEntryLocations)
{
	description = nDescription;
	roomID = nRoomID;
	roomItems = nRoomItems;
	entryLocations = nEntryLocations;
}

Room::Room(string nDescription, int nRoomID, vector<Item> nRoomItems, vector<Entry> nEntryLocations, vector<Location> nEnemyLocations)
{
	description = nDescription;
	roomID = nRoomID;
	roomItems = nRoomItems;
	entryLocations = nEntryLocations;
	enemyLocations = nEnemyLocations;
}

string Room::getDescription()
{
	return description;
}

int Room::getRoomID()
{
	return roomID;
}

Entry Room::getEntryByIndex(const int& index)
{
	return entryLocations.at(index);
}


void Room::displayEntryPoints()
{
	int x;
	int y;

	cout << "Entries are found at:" << endl;
	for (unsigned i = 0; i < entryLocations.size(); i++)
	{
		x = entryLocations.at(i).getXLoc();
		y = entryLocations.at(i).getYLoc();

		cout << "(" << x << ", " << y << ")" << endl;
	}
}


void Room::displayItems()
{
	vector<Item>::iterator itemIter;

	for (itemIter = roomItems.begin(); itemIter != roomItems.end(); itemIter++)
	{
		itemIter->printAllItemDetails();
	}
}

void Room::addNewEntryPoint(Entry newEntry)
{
	entryLocations.push_back(newEntry);
}

vector<Entry> Room::getEntryLocations()
{
	return entryLocations;
}

vector<Location> Room::getEnemyLocations()
{
	return enemyLocations;
}

void Room::removeEnemyLocation(const int& x, const int& y)
{
	bool found = false;
	int index = 0;

	while (index < enemyLocations.size() && !found)
	{
		if (x == enemyLocations.at(index).x && y == enemyLocations.at(index).y)
		{
			found = true;
			enemyLocations.erase(enemyLocations.begin() + index);
		}

		index++;
	}
}
