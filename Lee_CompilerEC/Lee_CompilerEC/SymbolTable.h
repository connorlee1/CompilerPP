#pragma once

#include "tableEntry.h"


class SymbolTable
{
public:
	SymbolTable();
	~SymbolTable();

	tableEntry* getEntryTable();


private:

	tableEntry entries[100];
	int entryIndex;


};

SymbolTable::SymbolTable()
{
	entryIndex = 0;
}

SymbolTable::~SymbolTable()
{
}

tableEntry* SymbolTable::getEntryTable()
{
	return entries;
}