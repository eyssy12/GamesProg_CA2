
#ifndef MAP_H
#define MAP_H

#include <string>
#include <vector>
#include "Room.h"
#include "Player.h"

using std::vector;

class Map
{

public:

	Map(vector<Room> rooms);

	Room getCurrentRoom();
	Room getRoomByID(const int& searchID);
	vector<Room> getAllRooms();

	int getBombsCount();
	int getPlayerMoveCount();
	int getPlayerXPos();
	int getPlayerYPos();

	bool getPlayerProgressState();
	bool getPlayerQuitState();

	bool gameStatus();
	void translateUserInput(Player& player, const std::string& input);
	void showControls();
	void movePlayer(const std::string& direction);
	void checkUserPosition();
	void checkPlayerProgress();
	bool checkPlayerLife(Player& player);
	void checkEnemyEncounter(Player& player);
	void loadRoom(Entry entry);
	void restart();

	void battle(Player& player);

	void addNewRoomToMap(Room newRoom);
	void displayPlayerLocation();
	void displayAllRoomDetails();
	void displayCurrentRoomDetails();

private:
	vector<Room> rooms;
	Room currentRoom;
	bool progressState;
	bool playerQuitState;
	bool playerAlive;

	int playerXPos;
	int playerYPos;

	int bombsCount;
	int playerMoveCount;
};

#endif