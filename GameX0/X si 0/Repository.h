#pragma once
#include <map>
#include "CellState.h"

using namespace std;

class Repository
{
private:
	map<pair<int, int>, CellState> cells;
	int tableDim;
public:
	Repository();
	Repository(int tableDim);
	~Repository();

	void initData();

	int getTableDim();
	CellState get(int x, int y);

	void add(int x, int y, CellState state);
	void update(int x, int y, CellState state);
};