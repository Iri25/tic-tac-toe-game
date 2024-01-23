#include "UserInterface.h"
#include <iostream>
#include <string>
#include "RepositoryException.h"

UserInterface::UserInterface()
{
}

UserInterface::UserInterface(Service service)
{
	this->service = service;
}

UserInterface::~UserInterface()
{
}

void UserInterface::printGameState()
{
	cout << "*******************************\n";
	for (int i = 0; i < this->service.getTableDim(); i++)
	{
		for (int j = 0; j < this->service.getTableDim(); j++)
		{
			switch (this->service.get(i, j))
			{
			case CellState::X:
				cout << "X ";
				break;
			case CellState::O:
				cout << "O ";
				break;
			case CellState::Unoccupied:
				cout << "_ ";
			}
		}
			cout << "\n";
	}
	cout << "\n*******************************\n";
}

void UserInterface::chooseXO()
{
	string opt;
	do 
	{
		cout << "Cu care caracter vreti sa jucati, X sau O?";
		getline(cin, opt);
	}
	while (opt != "X"&& opt != "x" && opt != "O" && opt != "o" && opt != "0");
	if (opt == "X"|| opt == "x")
	{
		this->usersChoice = CellState::X;
		this->itIsUsersTurn = true;
	}
	else 
	{
		this->usersChoice = CellState::O;
		this->itIsUsersTurn = false;
	}
}

void UserInterface::makeAUsersMove()
{
	string userInput;
	int x = -1, y = -1;
	bool readDataIsValid, isCellFree;
	do 
	{
		readDataIsValid = true;
		isCellFree = true;
		cout << "Pe ce pozitie vreti sa jucati? Formatul este {x} {y}.";
		getline(cin, userInput);
		try
		{
			x = stoi(userInput.substr(0, userInput.find(" ")));
			y = stoi(userInput.substr(userInput.find(" "), userInput.length()));
			isCellFree = this->service.isCellFree(x - 1, y - 1);
		}
		catch (RepositoryException& e)
		{
			isCellFree = false;
			cout << e.what();
			cout << " Mai incercati: ";
		}
		catch (const std::exception&)
		{
			readDataIsValid = false;
			cout << "Date invalide! Formatul este {x} {y}.Mai incercati: ";
		}
	}
	while (!readDataIsValid || !isCellFree);
	try 
	{
		this->service.makeAMove(x - 1, y - 1, usersChoice);
	}
	catch (exception e)
	{
		cout << e.what();
	}
}

void UserInterface::startGame()
{
	this->chooseXO();
	bool isThereAWinner = false;
	bool isTableFull = false;
	do 
	{
		if (this->itIsUsersTurn)
		{
			this->makeAUsersMove();
		}
		else
		{
			this->service.makeARandomMove(usersChoice == CellState::X ? CellState::	O : CellState::X);
		}
		isThereAWinner = this->service.isThereAWinner();
		isTableFull = this->service.isTableFull();
		this->printGameState();
		itIsUsersTurn = !itIsUsersTurn;
	} 
	while (!isThereAWinner && !isTableFull);
	if (isTableFull && !isThereAWinner)
	{
		cout << "Remiza!";
	}
	else
	{
		if (itIsUsersTurn)
		{
			cout << "Computerul a castigat!";
		}
		else
		{
			cout << "Tu ai castigat!";
		}
	}
}