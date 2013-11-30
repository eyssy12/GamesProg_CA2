
#include <vector>
#include <iostream>
#include <string>

#include "Inventory.h"
#include "Item.h"
#include "Map.h"
#include "Player.h"
#include "Weapon.h"
#include "Room.h"
#include "HealingKit.h"
#include "Utility.h"
#include "Location.h"

using namespace std;

vector<Room> buildRooms()
{
	vector<Room> basicMap;

	vector<Entry> safeHouseEntries;
	Entry e(0, 2, 1);
	safeHouseEntries.push_back(e);

	vector<Entry> mainHallEntries;
	Entry e1(0, 0, 2);
	Entry e2(-3, 3, 3);
	Entry e3(3, 3, 4);
	Entry e4(0, 5, 5);
	mainHallEntries.push_back(e1);
	mainHallEntries.push_back(e2);
	mainHallEntries.push_back(e3);
	mainHallEntries.push_back(e4);

	vector<Entry> supplyRoomEntries;
	Entry e5(3, 3, 6);
	supplyRoomEntries.push_back(e5);

	vector<Entry> wineCellarEntries;
	Entry e6(-3, 3, 7);
	wineCellarEntries.push_back(e6);

	vector<Entry> labEntries;
	Entry e7(0, 0, 8);
	labEntries.push_back(e7);

	vector<Location> mainHallEnemyLocations;
	Location loc1;
	loc1.x = -2;
	loc1.y = 3;
	loc1.id = 1;
	Location loc2;
	loc2.x = 0;
	loc2.y = 3;
	loc2.id = 2;
	Location loc3;
	loc3.x = 2;
	loc3.y = 3;
	loc3.id = 3;
	mainHallEnemyLocations.push_back(loc1);
	mainHallEnemyLocations.push_back(loc2);
	mainHallEnemyLocations.push_back(loc3);

	vector<Location> supplyRoomEnemyLocations;
	vector<Location> wineCellarEnemyLocations;
	vector<Location> labEnemyLocations;

	//				 description, id , items vector
	Room safeHouse("Safehouse", 1, safeHouseEntries);
	Room mainHall("Main hall", 2, mainHallEntries, mainHallEnemyLocations);
	Room supplyRoom("Supply room", 3, supplyRoomEntries, supplyRoomEnemyLocations);
	Room wineCellar("Wine cellar", 4, wineCellarEntries, wineCellarEnemyLocations);
	Room lab("Laboratory", 5, labEntries, labEnemyLocations);

	basicMap.push_back(safeHouse);
	basicMap.push_back(mainHall);
	basicMap.push_back(supplyRoom);
	basicMap.push_back(wineCellar);
	basicMap.push_back(lab);

	return basicMap;
}

void displayWelcome()
{
	cout << "-------------------------------------------------" << endl;
	cout << "Welcome to the RPG Game" << endl;
	cout << "-------------------------------------------------" << endl;
	printMessageWithBorders("During the game, enter HELP to show all commands!");

	getValidInput("Enter 1 to proceed to your character creation: ", 1, 1);
}

Player createPlayer()
{
	printMessageWithBorders("...CHARACTER CREATION STAGE...");

	string name = "";
	cout << "Enter your HERO's name: ";
	cin >> name;

	Inventory defaultStartInventory;
	//HealingKit(std::string name, ItemType itemType, Reusability isReusable, int healingRate);
	HealingKit h1("Health Potion", Item::ItemType::HEALING, Item::Reusability::NO, 15);
	HealingKit h2("Health Potion", Item::ItemType::HEALING, Item::Reusability::NO, 15);
	HealingKit h3("Health Potion", Item::ItemType::HEALING, Item::Reusability::NO, 15);
	HealingKit h4("Health Potion", Item::ItemType::HEALING, Item::Reusability::NO, 15);
	defaultStartInventory.addHealingKit(h1);
	defaultStartInventory.addHealingKit(h2);
	defaultStartInventory.addHealingKit(h3);
	defaultStartInventory.addHealingKit(h4);

	// present with options to choose a starting werapon;
	// Weapon(std::string name, ItemType itemType, Reusability isReusable, int damageRate);
	vector<Weapon> startWeapons;
	vector<Weapon>::iterator weaponIter;
	Weapon startWep1("Dagger", Item::ItemType::WEAPON, Item::Reusability::YES, 15);
	Weapon startWep2("Short Sword", Item::ItemType::WEAPON, Item::Reusability::YES, 15);
	Weapon startWep3("Small Axe", Item::ItemType::WEAPON, Item::Reusability::YES, 15);
	Weapon startWep4("Long Bamboo Stick", Item::ItemType::WEAPON, Item::Reusability::YES, 15);
	startWeapons.push_back(startWep1);
	startWeapons.push_back(startWep2);
	startWeapons.push_back(startWep3);
	startWeapons.push_back(startWep4);

	cout << endl;
	cout << "Choice of weapons to start with (all have the same damage rate)" << endl;
	cout << "---------------------------------------------------------------" << endl;
	int choice = 1;
	for (weaponIter = startWeapons.begin(); weaponIter != startWeapons.end(); weaponIter++)
	{
		cout << choice << ") " << weaponIter->getItemName() << endl;
		choice++;
	}

	int weaponChoice = getValidInput("Take a pick: ", 1, 4);
	Weapon playerStartWeapon = startWeapons.at(weaponChoice - 1);

	Player newPlayer(name, playerStartWeapon, defaultStartInventory);
	printMessageWithBorders("New character created - game is ready!");
	getValidInput("Enter 1 to begin: ", 1, 1);

	return newPlayer;
}

void displayGameEnd()
{
	cout << endl;
	cout << "------------------------------------------------------------------" << endl;
	cout << "Bad Luck! Unfortunately, your character didn't find all the bombs on time!" << endl;
	cout << "As of consequence, the whole map (and the area of 1000km^2) blew up," << endl;
	cout << "your character died and they are remebered as a failure." << endl;
	cout << endl;
	cout << "Better luck next time!" << endl;
	cout << "------------------------------------------------------------------" << endl;
	cout << endl;
}

void displayGameEndPlayerQuitted()
{
	cout << endl;
	cout << "------------------------------------------------------------------" << endl;
	cout << "You've quit the game!" << endl;
	cout << "Because you decided to be a coward and save yourself from the threat" << endl;
	cout << "There was nobody else who could've defused the bombs, resulting in" << endl;
	cout << "The surroundong area to be annahilated." << endl;
	cout << "Knowing this, the enemy got a good laugh about you and the agancy you work(ED) for." << endl;
	cout << "------------------------------------------------------------------" << endl;
	cout << endl;
}

void printGap()
{
	cout << endl;
	cout << endl;
}

int main()
{

	string command = "";

	// start of the game
	displayWelcome();
	Player player = createPlayer();

	vector<Room> mainRooms = buildRooms();
	Map gameMap(mainRooms);

	bool playAgain = false;
	// in game action
	do
	{
		while (gameMap.gameStatus() == 0) // keep playing until the status becomes 1 , 1 = a game condition has been met somewhere
		{
			cout << "Room: " << gameMap.getCurrentRoom().getDescription() << endl;
			cout << "Position " << "(" << gameMap.getPlayerXPos() << ", " << gameMap.getPlayerYPos() << ")" << endl;
			cout << "------------------------" << endl;
			cout << "Bombs left to find: " << gameMap.getBombsCount() << endl;
			cout << "Moves left: " << gameMap.getPlayerMoveCount() << endl;
			cout << "------------------------" << endl;
			cout << endl;
			cout << "Enter command: ";
			cin >> command;
			printGap();

			gameMap.translateUserInput(player, command);
			gameMap.checkPlayerLife(player);

			// if the player hasn't entered the quit option,
			// proceed as normal with game
			if (gameMap.gameStatus() != 1)
			{
				gameMap.checkEnemyEncounter(player);
				gameMap.checkUserPosition();
				gameMap.checkPlayerProgress();
			}
		}

		if (gameMap.getPlayerQuitState() == 1)
		{
			displayGameEndPlayerQuitted();
		}
		else
		{
			displayGameEnd();
		}

		playAgain = getValidYesNoInput("Do you want to play again?");
		if (playAgain)
		{
			gameMap.restart();
		}
	} while (playAgain == true);

	return 0;
}