#include "Repository.h"
#include "RepositoryException.h"

Repository::Repository()
{
	this->tableDim = 0;
}

Repository::Repository(int tableDim)
{
	this->tableDim = tableDim;
	this->initData();
}

Repository::~Repository()
{
}

void Repository::initData()
{
	for (int i = 0; i < this->tableDim; i++)
	{
		for (int j = 0; j < this->tableDim; j++)
		{
			this->add(i, j, CellState::Unoccupied);
		}
	}
}

int Repository::getTableDim()
{
	return this->tableDim;
}

CellState Repository::get(int x, int y) throw(RepositoryException)
{
	if (x < 0 || y < 0 || x >= this->tableDim || y >= this->tableDim)
	{
		throw RepositoryException("Indecsi in afara limitelor");
	}
	return this->cells[make_pair(x,y)];
}

void Repository::add(int x, int y, CellState state)
{
	this->cells.insert({ make_pair(x, y), state });
}

void Repository::update(int x, int y, CellState state) throw(RepositoryException)
{
	if (x < 0 || y < 0 || x >= this->tableDim || y>= this->tableDim)
	{
		throw RepositoryException("Indecsi in afara limitelor");
	}
	this->cells[make_pair(x, y)] = state;
}