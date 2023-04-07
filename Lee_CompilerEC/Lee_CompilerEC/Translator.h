#pragma once

#include "SymbolTable.h"


class Translator
{
public:
	Translator();
	~Translator();

	void translate();


private:
	SymbolTable table;
	int commandarr[100];
	int flagArr[100];
};

Translator::Translator()
{
	for (int temp = 0; temp < 100; temp++)
	{
		flagArr[temp] = -1;
		commandarr[temp] = 0;
	}

	



}

Translator::~Translator()
{
}

void Translator::translate()
{
	std::ifstream infile;

	infile.open("SimpleTronScript.txt", std::ios::in);

	char tempString[1000];

	std::string command;

	char variable = '\0';

	int index = 0, cmdIndex = 0, varlocation = 99, location = 0;

	while (!infile.eof())
	{
		infile.getline(tempString, 1000);

		table.getEntryTable()[index].setType('L');
		table.getEntryTable()[index].setSymbol(atoi(tempString));
		table.getEntryTable()[index].setLocation(location);
		location++;


		index++;

		command = strtok(nullptr, " ");

		if (command == "rem")
		{

		}
		else if (command == "input")
		{
			variable = *(strtok(nullptr, " "));
			bool isFound = false;

			for (int tableIndex = 99; tableIndex >= 0; tableIndex--)
			{
				if (table.getEntryTable()[tableIndex].getType() == 'V')
				{
					if (table.getEntryTable()[tableIndex].getSymbol() == variable)
					{
						commandarr[cmdIndex] = 1000 + table.getEntryTable()[tableIndex].getLocation();
						cmdIndex++;
						isFound = true;
						break;
					}
				}
			}

			if (isFound == false)
			{
				table.getEntryTable()[index].setType('V');
				table.getEntryTable()[index].setSymbol((int)variable);
				table.getEntryTable()[index].setLocation(varlocation);
				commandarr[cmdIndex] = 1000 + varlocation;
				cmdIndex++;
				varlocation--;
			}

			



		}
		else if (command == "let")
		{

		}
		else if (command == "print")
		{
			
			
			variable = *(strtok(nullptr, " "));

			for (int tableIndex = 99; tableIndex >= 0; tableIndex--)
			{
				if (table.getEntryTable()[tableIndex].getType() == 'V')
				{
					if (table.getEntryTable()[tableIndex].getSymbol() == variable)
					{
						commandarr[cmdIndex] = 2000 + table.getEntryTable()[tableIndex].getLocation();
						cmdIndex++;
						break;
					}
				}
			}

			

			

		}
		else if (command == "goto")
		{
			int gotoLine = 0;
			bool isFound = false;

			gotoLine = atoi(strtok(nullptr, " "));

			for (int tableIndex = 99; tableIndex >= 0; tableIndex--)
			{
				if (table.getEntryTable()[tableIndex].getType() == 'L')
				{
					if (table.getEntryTable()[tableIndex].getSymbol() == gotoLine)
					{
						commandarr[cmdIndex] = 4000 + table.getEntryTable()[tableIndex].getLocation();
						cmdIndex++;
						isFound = true;
						break;
					}
				}
			}
			if (isFound == false)
			{
				commandarr[cmdIndex] = 4000;
				cmdIndex++;
			}


		}
		else if (command == "if")
		{

		}
		else if (command == "end")
		{
			commandarr[cmdIndex] = 4300;
		}
		else
		{

		}

		memset(tempString, '\0', 1000);

	}


}