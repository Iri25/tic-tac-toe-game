#pragma once
#include "Service.h"

class UserInterface
{
private:
	Service service;

	bool itIsUsersTurn;
	CellState usersChoice;

	void printGameState();
	void chooseXO();
	void makeAUsersMove();
public:
	UserInterface();
	UserInterface(Service service);
	~UserInterface();

	void startGame();
};