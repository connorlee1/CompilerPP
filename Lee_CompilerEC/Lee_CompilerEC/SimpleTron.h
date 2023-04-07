#pragma once

#include "Header.h"

class SimpleTron
{
public:
	SimpleTron();
	~SimpleTron();

	void enterInstructions();
	
	void excecuteInstructions();

	void runProgram();

	void memDump();

	void throwError(int i);

private:

	int* memory;
	int accumulator;
	int operationCode;
	int operand;
	int instructionRegister;
	int instructionCounter;

};

SimpleTron::SimpleTron()
{
	memory = new int[100];

	for (int i = 0; i < 100; i++)
	{
		memory[i] = 0;
	}

	accumulator = 0;
	operationCode = 0;
	operand = 0;
	instructionRegister = 0;
	instructionCounter = 0;
}

SimpleTron::~SimpleTron()
{
}

void SimpleTron::enterInstructions()
{

	cout << "*** Welcome to Simpletron! ***" << endl;
	cout << "*** Please enter your program one instruction ***" << endl;
	cout << "*** (or data word) at a time.I will type the ***" << endl;
	cout << "*** location numberand a question mark(? ). ***" << endl;
	cout << "*** You then type the word for that location. ***" << endl;
	cout << "*** Type the sentinel - 99999 to stop entering ***" << endl;
	cout << "*** your program. ***" << endl;

	int memIndex = 0;
	int input = 0;


	while (memIndex < 100 || input != 4300)
	{
		cout << memIndex << "? ";
		cin >> input;

		while ((input != -99999 && input < -9999) || input > 9999)
		{
			cout << "Invalid input try again " << endl;
			cout << memIndex << "?" << endl;

			cin >> input;
		}

		memory[memIndex] = input;
		memIndex++;

		if (input == -99999)
		{
			break;
		}
	}

	cout << "*** Program loading completed***" << endl;
	cout << "*** Program execution begins***" << endl;


}

void SimpleTron::excecuteInstructions()
{
	instructionRegister = memory[instructionCounter];

	operationCode = instructionRegister / 100;
	operand = instructionRegister % 100;

	instructionCounter++;

	switch (operationCode)
	{
	case 10://Read
		cin >> memory[operand];

		break;
	case 11://write
		cout << memory[operand] << endl;

		break;
	case 20://load
		accumulator = memory[operand];

		break;
	case 21://store
		memory[operand] = accumulator;

		break;
	case 30://add
		if (accumulator + memory[operand] > 9999 || accumulator + memory[operand] < -9999)
		{
			throwError(0);
		}
		else
		{
			accumulator += memory[operand];
		}
	
		break;
	case 31://subtract
		if (accumulator - memory[operand] > 9999 || accumulator - memory[operand] < -9999)
		{
			throwError(0);
		}
		else
		{
			accumulator -= memory[operand];
		}

		break;
	case 32://divide
		if (accumulator / memory[operand] > 9999 || accumulator / memory[operand] < -9999)
		{
			throwError(0);
		}
		else if (memory[operand] == 0)
		{
			throwError(1);
		}
		else
		{
			accumulator /= memory[operand];
		}

		break;
	case 33://multiply
		if (accumulator * memory[operand] > 9999 || accumulator * memory[operand] < -9999)
		{
			throwError(0);
		}
		else
		{
			accumulator *= memory[operand];
		}

		break;
	case 40://branch
		instructionCounter = operand;

		break;
	case 41://branchneg
		if (accumulator < 0)
		{
			instructionCounter = operand;
		}

		break;
	case 42://branchzero
		if (accumulator == 0)
		{
			instructionCounter = operand;
		}

		break;
	case 43://halt
		cout << "***Simpletron execution terminated ***" << endl;
		this->memDump();

		break;
	
	default:
		break;
	}

	

}

void SimpleTron::memDump()
{
	cout << "REGISTERS:" << endl;
	cout << "accumulator:             " << std::showpos << std::setw(5) << std::setfill('0') << std::internal << accumulator << endl;
	cout << "instructionCounter:         " << std::showpos << std::setw(2) << std::setfill('0') << std::internal << instructionCounter << endl;
	cout << "instructionRegister:     " << std::showpos << std::setw(5) << std::setfill('0') << std::internal << instructionRegister << endl;
	cout << "operationCode:              " << std::showpos << std::setw(2) << std::setfill('0') << std::internal << operationCode << endl;
	cout << "operand:                    " << std::showpos << std::setw(2) << std::setfill('0') << std::internal << operand << endl;
	cout << "" << endl;
	cout << "MEMORY:" << endl;
	cout << "       0     1     2     3     4     5     6     7     8     9" << endl;
	
	cout << "0  ";

	for (int i = 0; i < 10; i++) 
	{
		cout << std::showpos << std::setw(5) << std::setfill('0') << std::internal << memory[i] << " ";
	}

	cout << endl;

	for (int j = 10; j < 100; j = j + 10) 
	{
		cout << std::noshowpos << j << " ";
		
		for (int i = 0; i < 10; i++) 
		{
			cout << std::showpos << std::setw(5) << std::setfill('0') << std::internal << memory[j + i] << " ";
		}

		cout << endl;

	}

}

void SimpleTron::runProgram()
{
	while (instructionCounter < 100)
	{
		this->excecuteInstructions();
	}

}

void SimpleTron::throwError(int i) 
{
	if (i == 0) {
		cout << "An overflow error has occured. The program will now exit..." << endl;
		instructionCounter = 100;
		memDump();
	}
	if (i == 1) {
		cout << "A divide by zero error has occured. The program will now exit..." << endl;
		instructionCounter = 100;
		memDump();
	}

}

