
#include <iostream>

#include "Generics.h"
#include "Utility.h"
#include "Map.h"
#include "Room.h"
#include "Player.h"

using namespace std;

vector<Room>::iterator roomIter;
const int MAX_BOMBS = 3;
const int MAX_MOVES = 15;

Map::Map(vector<Room> newRooms)
{
	rooms = newRooms;
	currentRoom = rooms.at(0);
	progressState = 0;
	playerQuitState = 0;
	playerAlive = 0;

	playerXPos = 0;
	playerYPos = 0;

	bombsCount = MAX_BOMBS;
	playerMoveCount = MAX_MOVES;
};

Room Map::getCurrentRoom()
{
	return currentRoom;
}

Room Map::getRoomByID(const int& searchID)
{
	Room room;
	bool found = false;
	unsigned index = 0;

	while (index < rooms.size() && !found)
	{
		if (rooms.at(index).getRoomID() == searchID)
		{
			room = rooms.at(index);
			found = true;
		}

		index++;
	}

	return room;
}

vector<Room> Map::getAllRooms()
{
	return rooms;
}

int Map::getBombsCount()
{
	return bombsCount;
}

int Map::getPlayerMoveCount()
{
	return playerMoveCount;
}

int Map::getPlayerXPos()
{
	return playerXPos;
}

int Map::getPlayerYPos()
{
	return playerYPos;
}

void Map::movePlayer(const string& direction)
{
	//x axis
	if (direction == "LEFT" || direction == "left")
	{
		playerXPos--;
	}
	else if (direction == "RIGHT" || direction == "right")
	{
		playerXPos++;
	}
	else if (direction == "UP" || direction == "up")
	{
		playerYPos++;
	}
	else
	{
		playerYPos--;
	}

	playerMoveCount--;
}

void Map::translateUserInput(Player& player, const string& input)
{
	bool wait = true;

	// show all the available commands
	if (input == "HELP" || input == "help")
	{
		showControls();
	}
	// deal with movement
	else if (input == "UP" || input == "up"
		|| input == "DOWN" || input == "down"
		|| input == "LEFT" || input == "left"
		|| input == "RIGHT" || input == "right")
	{
		movePlayer(input);
		wait = false;
	}
	// deal with player linked commands
	else if (input == "I" || input == "i")
	{
		player.showPlayerInventory();
	}
	else if (input == "U" || input == "u")
	{
		player.showPlayerStats();
	}
	// deal with room associated commands
	else if (input == "O" || input == "o")
	{
		displayCurrentRoomDetails();
	}
	else if (input == "Q" || input == "q")
	{
		bool choice = getValidYesNoInput("Are you sure you want to quit?");

		if (choice == true)
		{
			playerQuitState = 1;
		}
		wait = false;
	}
	else if (input == "1")
	{
		if (player.useHealingPotion() == false)
		{
			printMessageWithBorders("No healing potions in the inventory!");
		}
		else
		{
			printMessageWithBorders("Healing potion used!");
		}

		wait = false;
	}
	else
	{
		printMessageWithBorders("*** Unknown command! ***");
		wait = false;
	}

	// if the user DIDN'T use any of the move commands
	// we allow the player to exit the inventory, etc when they wish
	// acts as a flow control...
	if (wait == true)
	{
		getValidInput("Enter 1 to exit: ", 1, 1);
	}
}

bool Map::gameStatus()
{
	if (progressState == 1)
		return 1;
	else if (playerQuitState == 1)
		return 1;
	else if (playerAlive == 1)
		return 1;
	else
		return 0;
}

void Map::showControls()
{
	cout << endl;
	cout << "You can enter the following commands: " << endl;
	cout << "------------------------------------------" << endl;
	cout << "MOVEMENT: " << "UP, " << "DOWN, " << "LEFT, " << "RIGHT" << endl;
	cout << "PLAYER: " << "U - Stats, " << "I - Inventory" << endl;
	cout << "PLAYER SHORTCUTS: " << "1 - Use healing potion" << endl;
	cout << "ROOM: " << "O - Room Info" << endl;
}

void Map::checkEnemyEncounter(Player& player)
{
	Location loc;
	bool found = false;
	unsigned index = 0;

	while (index < currentRoom.getEnemyLocations().size() && !found)
	{
		loc.x = currentRoom.getEnemyLocations().at(index).x;
		loc.y = currentRoom.getEnemyLocations().at(index).y;


		if ((playerXPos == loc.x) && (playerYPos == loc.y))
		{
			found = true;
			printMessageWithBorders("Enemy encountered!!!");
			getValidInput("Enter 1 to engage in battle: ", 1, 1);

			battle(player);
			currentRoom.removeEnemyLocation(loc.x, loc.y);
		}

		index++;
	}
}

void Map::battle(Player& player)
{
	int rand = 0;
	int wepDamage = 0;
	Enemy e;

	rand = getRandomNumber(1, 100);
	if (rand <= 20)
	{
		e = createEnemy(Enemy::EnemyType::STRONG);
	}
	else if (rand <= 60)
	{
		e = createEnemy(Enemy::EnemyType::WEAK);
	}
	else
	{
		e = createEnemy(Enemy::EnemyType::MEDIUM);
	}

	bool finished = false;
	while (!finished)
	{
		cout << endl;
		cout << "Your hitpoints: " << player.getHP() << endl;
		cout << "Enemy hitpoints: " << e.getHP() << endl;
		cout << "-------------------------" << endl;
		cout << endl;
		printMessageWithBorders("Your choies:");
		int choice = getValidInput("1. Attack", 1, 1);

		if (choice == 1)
		{
			rand = getRandomNumber(1, 100);

			if (rand >= 50)
			{
				wepDamage = player.getWeapon().getDamageRate();

				e.setHP(e.getHP() - wepDamage);
			}

			rand = getRandomNumber(1, 100);

			if (rand >= 65)
			{
				wepDamage = e.getWeapon().getDamageRate();

				player.setHP(player.getHP() - wepDamage);
			}
		}

		cout << endl;
		if (e.getHP() <= 0 || player.getHP() <= 0)
		{
			finished = true;

			if (player.getHP() > 0)
			{
				printMessageWithBorders("You won the battle!");
			}
			else
			{
				printMessageWithBorders("You lost!");
				playerAlive = 1;
			}
		}
	}
}

bool Map::checkPlayerLife(Player& player)
{
	if (playerAlive == 1)
	{
		return 1;
	}

	return 0;
}

void Map::checkUserPosition()
{
	Entry entry;
	bool found = false;
	unsigned index = 0;

	bool toEnter;

	while (index < currentRoom.getEntryLocations().size() && !found)
	{
		entry = currentRoom.getEntryByIndex(index);

		if ((playerXPos == entry.getXLoc()) && (playerYPos == entry.getYLoc()))
		{
			printMessageWithBorders("You've come accress a door!");
			toEnter = getValidYesNoInput("Do you want to enter this room?");
			found = true;

			if (toEnter == true)
			{
				loadRoom(entry);
				printMessageWithBorders("Room loaded.");
			}
		}

		index++;
	}
}

void Map::loadRoom(Entry entry)
{
	Room newRoom;
	int entryID = entry.getID();

	// MAINHALL <-----> SAFEHOUSE
	if (entryID == 1) // safehouse -> mainhall
	{
		newRoom = getRoomByID(2);
		currentRoom = newRoom;

		playerXPos = newRoom.getEntryLocations().at(0).getXLoc();
		playerYPos = newRoom.getEntryLocations().at(0).getYLoc();
	}
	else if (entryID == 2) // mainhall -> safehouse
	{
		newRoom = getRoomByID(1);
		currentRoom = newRoom;

		playerXPos = newRoom.getEntryLocations().at(0).getXLoc();
		playerYPos = newRoom.getEntryLocations().at(0).getYLoc();
	}

	// MAINHALL <-----> SUPPLY ROOM
	if (entryID == 3) // mainhall -> supply room
	{
		newRoom = getRoomByID(3);
		currentRoom = newRoom;

		playerXPos = newRoom.getEntryLocations().at(0).getXLoc();
		playerYPos = newRoom.getEntryLocations().at(0).getYLoc();
	}
	else if (entryID == 6) // supply room -> mainhall
	{
		newRoom = getRoomByID(2);
		currentRoom = newRoom;

		playerXPos = newRoom.getEntryLocations().at(1).getXLoc();
		playerYPos = newRoom.getEntryLocations().at(1).getYLoc();
	}

	// MAINHALL <-----> WINE CELLAR
	if (entryID == 4) // mainhall -> wine cellar
	{
		newRoom = getRoomByID(4);
		currentRoom = newRoom;

		playerXPos = newRoom.getEntryLocations().at(1).getXLoc();
		playerYPos = newRoom.getEntryLocations().at(1).getYLoc();
	}
	else if (entryID == 7) // wine cellar -> mainhall
	{
		newRoom = getRoomByID(2);
		currentRoom = newRoom;

		playerXPos = newRoom.getEntryLocations().at(2).getXLoc();
		playerYPos = newRoom.getEntryLocations().at(2).getYLoc();
	}

	// MAINHALL <-----> LAB
	if (entryID == 5) // mainhall -> lab
	{
		newRoom = getRoomByID(5);
		currentRoom = newRoom;

		playerXPos = newRoom.getEntryLocations().at(0).getXLoc();
		playerYPos = newRoom.getEntryLocations().at(0).getYLoc();
	}
	else if (entryID == 8) // lab -> mainhall
	{
		newRoom = getRoomByID(2);
		currentRoom = newRoom;

		playerXPos = newRoom.getEntryLocations().at(3).getXLoc();
		playerYPos = newRoom.getEntryLocations().at(3).getYLoc();
	}
}

void Map::checkPlayerProgress()
{
	if ((bombsCount >= 0) && (playerMoveCount >= 0))
	{
		progressState = 0;
	}
	else
	{
		progressState = 1;
	}
}

bool Map::getPlayerProgressState()
{
	return progressState;
}

bool Map::getPlayerQuitState()
{
	return playerQuitState;
}

void Map::restart()
{
	currentRoom = rooms.at(0);
	progressState = 0;
	playerQuitState = 0;
	playerAlive = 0;

	playerXPos = 0;
	playerYPos = 0;

	bombsCount = MAX_BOMBS;
	playerMoveCount = MAX_MOVES;
}
void Map::displayAllRoomDetails()
{
	int i = 1;

	for (roomIter = rooms.begin(); roomIter != rooms.end(); roomIter++)
	{
		cout << i << endl;
		cout << "Description: " << roomIter->getDescription() << endl;
		cout << "Room ID: " << roomIter->getRoomID() << endl;
		cout << endl;

		i++;
	}
}

void Map::displayCurrentRoomDetails()
{
	cout << "Description: " << currentRoom.getDescription() << endl;
	cout << "Room ID: " << currentRoom.getRoomID() << endl;
	cout << endl;
	currentRoom.displayEntryPoints();
	cout << endl;
}