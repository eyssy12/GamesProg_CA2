#ifndef ROOM_H
#define ROOM_H

class Room
{

public:

	enum ExitType
	{
		YES = true, NO = false
	};

	Room();
	Room(ExitType nExit, ExitType sExit, ExitType wExit, ExitType eExit);

private:
	bool northExit;
	bool sourthExit;
	bool westExit;
	bool eastExit;


};

#endif