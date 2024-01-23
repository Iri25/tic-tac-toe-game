#include "Service.h"
#include "RepositoryException.h"

Service::Service()
{
}

Service::Service(Repository repository)
{
	this->repository = repository;
}

Service::~Service()
{
}

int Service::getTableDim()
{
	return this->repository.getTableDim();
}

CellState Service::get(int x, int y) throw(RepositoryException)
{
	return this->repository.get(x, y);
}

bool Service::isThereAWinner()
{
	for (int i = 0; i < this->getTableDim(); i++)
	{
		if (this->repository.get(i, 0) != CellState::Unoccupied) 
		{
			bool lineIsWinner = true;
			for (int j = 1; j < this->getTableDim() && lineIsWinner; j++)
			{
				if (this->repository.get(i, j) != this->repository.get(i, 0))
				{
					lineIsWinner = false;
				}
			}
			if (lineIsWinner)
			{
				return true;
			}
		}
	}

	for (int j = 0; j < this->getTableDim(); j++)
	{
		if (this->repository.get(0, j) != CellState::Unoccupied)
		{
			bool colIsWinner = true;
			for (int i = 1; i < this->getTableDim() && colIsWinner; i++)
			{
				if (this->repository.get(i, j) != this->repository.get(0, j))
				{
					colIsWinner = false;
				}
			}
			if (colIsWinner)
			{
				return true;
			}
		}
	}
	
	if (this->repository.get(0, 0) != CellState::Unoccupied)
	{
		bool mainDiagIsWinner = true;
		for (int i = 1; i < this->getTableDim(); i++)
		{
			if (this->repository.get(i, i) != this->repository.get(0, 0))
			{
				mainDiagIsWinner = false;
			}
		}
		if (mainDiagIsWinner)
		{
			return true;
		}
	}

	if (this->repository.get(0, this->getTableDim() - 1) != CellState::Unoccupied)
	{
		bool secDiagIsWinner = true;
		for (int i = 1; i < this->getTableDim(); i++)
		{
			if (this->repository.get(i, getTableDim() - i - 1) != this->repository.get(0, this->getTableDim() - 1))
			{
				secDiagIsWinner = false;
			}
		}
		if (secDiagIsWinner)
		{
			return true;
		}
	}

	return false;
}

void Service::makeAMove(int x, int y, CellState state) throw(RepositoryException)
{
	this->repository.update(x, y, state);
}

void Service::makeARandomMove(CellState state)
{
	pair<int, int> randomMove = this->generateAMove();
	this->makeAMove(randomMove.first, randomMove.second, state);
}

pair<int, int> Service::generateAMove()
{
	int randomX, randomY;
	do 
	{
		randomX = rand() % (this->getTableDim());
		randomY = rand() % (this->getTableDim());
	}
	while (!this->isCellFree(randomX, randomY));

	return make_pair(randomX, randomY);
}

bool Service::isCellFree(int x, int y) throw(RepositoryException)
{
	return this->repository.get(x, y) == CellState::Unoccupied;
}


bool Service::isTableFull()
{
	for (int i = 0; i < this->getTableDim(); i++)
	{
		for (int j = 0; j < this->getTableDim(); j++)
		{
			if (this->repository.get(i, j) == CellState::Unoccupied)
			{
				return false;
			}
		}
	}
	return true;
}