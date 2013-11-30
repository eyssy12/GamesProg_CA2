

#ifndef ENTRY_H
#define ENTRY_H

class Entry
{

public:
	Entry();
	Entry(int x, int y, int id);


	int getXLoc();
	int getYLoc();
	int getID();
	void setEntryPoints(int x, int y);

private:
	int id;
	int x;
	int y;
};

#endif
