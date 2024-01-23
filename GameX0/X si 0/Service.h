#pragma once
#include "Repository.h"

class Service 
{
private:
	Repository repository;
public:
	Service();
	Service(Repository repository);
	~Service();

	int getTableDim();
	CellState get(int x, int y);

	bool isThereAWinner();

	void makeAMove(int x, int y, CellState state);
	void makeARandomMove(CellState state);

	pair<int, int> generateAMove();

	bool isCellFree(int x, int y);
	bool isTableFull();
};