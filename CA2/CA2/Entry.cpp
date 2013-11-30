

#include "Entry.h"

Entry::Entry()
{
	id = 0;
	x = 0;
	y = 0;
}

Entry::Entry(int newX, int newY, int nID)
{
	id = nID;
	x = newX;
	y = newY;
}

int Entry::getXLoc()
{
	return x;
}

int Entry::getYLoc()
{
	return y;
}

int Entry::getID()
{
	return id;
}

void Entry::setEntryPoints(int newX, int newY)
{
	x = newX;
	y = newY;
}

