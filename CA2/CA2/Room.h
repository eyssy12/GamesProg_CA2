#ifndef ROOM_H
#define ROOM_H

#include <string>
#include <vector>

#include "Enemy.h"
#include "Item.h"
#include "Entry.h"
#include "Location.h"

using std::vector;

class Room
{

public:

	Room();
	Room(std::string description, int roomID, vector<Entry> entryLocations, vector<Location> enemyLocations);
	Room(std::string description, int roomID, vector<Entry> entryLocations);
	Room(std::string description, int roomID, vector<Item> roomItems, vector<Entry> entryLocations);
	Room(std::string description, int roomID, vector<Item> roomItems, vector<Entry> entryLocations, vector<Location> enemyLocations);

	std::string getDescription();
	int getRoomID();
	Entry getEntryByIndex(const int& index);
	vector<Entry> getEntryLocations();
	vector<Location> getEnemyLocations();

	void addNewEntryPoint(Entry newEntry);
	void displayItems();
	void displayEntryPoints();
	void removeEnemyLocation(const int& x, const int& y);
private:

	std::string description;
	int roomID;

	vector<Item> roomItems;
	vector<Entry> entryLocations;
	vector<Location> enemyLocations;
};

#endif