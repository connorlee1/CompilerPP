#pragma once

#include "Header.h"


class tableEntry
{
public:
	tableEntry();
	~tableEntry();

	int getSymbol();

	char getType();

	int getLocation();

	void setSymbol(int newSymbol);

	void setType(char newType);

	void setLocation(int newLocation);


private:

	int symbol;
	char type;
	int location;

};

tableEntry::tableEntry()
{
}

tableEntry::~tableEntry()
{
}

int tableEntry::getSymbol()
{
	return symbol;
}

char tableEntry::getType()
{
	return type;
}

int tableEntry::getLocation()
{
	return location;
}

void tableEntry::setSymbol(int newSymbol)
{
	symbol = newSymbol;
}

void tableEntry::setType(char newType)
{
	type = newType;
}

void tableEntry::setLocation(int newLocation)
{
	location = newLocation;
}