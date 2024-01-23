#include "TestService.h"
#include "Service.h"
#include <cassert>
#include "RepositoryException.h"

TestService::TestService()
{
}

TestService::~TestService()
{
}

void TestService::testGetTableDim()
{
	Service service1;
	assert(service1.getTableDim() == 0);
	Repository repo(3);
	Service service2(repo);
	assert(service2.getTableDim() == 3);
}

void TestService::testGet()
{
	Repository repo(3);
	Service service(repo);
	try 
	{
		assert(service.get(0, 0) == CellState::Unoccupied);
		service.makeAMove(0, 0, CellState::X);
		assert(service.get(0, 0) == CellState::X);
	}
	catch (...) 
	{
		assert(false);
	}

	try 
	{
		service.get(-1, 0);
		assert(false);
	}
	catch (RepositoryException & e) 
	{

	}
	catch (...)
	{
		assert(false);
	}
	try 
	{
		service.get(0, -1);
		assert(false);
	}
	catch (RepositoryException & e)
	{

	}
	catch (...) 
	{
		assert(false);
	}

	try
	{
		service.get(-1, -1);
		assert(false);
	}
	catch (RepositoryException & e) 
	{

	}
	catch (...) 
	{
		assert(false);
	}

	try 
	{
		service.get(0, 4);

		assert(false);
	}
	catch (RepositoryException & e) 
	{

	}
	catch (...)
	{
		assert(false);
	}

	try
	{
		service.get(4, 0);
		assert(false);
	}
	catch (RepositoryException & e)
	{

	}
	catch (...) 
	{
		assert(false);
	}

	try 
	{
		service.get(4, 4);
		assert(false);
	}
	catch (RepositoryException & e)
	{

	}
	catch (...) 
	{
		assert(false);
	}

	try
	{
		service.get(-1, 4);
		assert(false);
	}
	catch (RepositoryException & e)
	{

	}
	catch (...)
	{
		assert(false);
	}
}

void TestService::testIsThereAWinner()
{
	Repository repo(3);
	Service service(repo);
	assert(service.isThereAWinner() == false);

	// check all rows winning possibilities
	for (int i = 0; i < service.getTableDim(); i++)
	{
		for (int j = 0; j < service.getTableDim(); j++)
		{
			service.makeAMove(i, j, CellState::X);
			bool result = service.isThereAWinner();
			assert(j == service.getTableDim() - 1 ? result : !result);
		}
		// cleanup row
		for (int j = 0; j < service.getTableDim(); j++)
		{
			service.makeAMove(i, j, CellState::Unoccupied);
		}
	}

	// check all columns winning possibilities
	for (int j = 0; j < service.getTableDim(); j++)
	{
		for (int i = 0; i < service.getTableDim(); i++)
		{
			service.makeAMove(i, j, CellState::X);
			bool result = service.isThereAWinner();
			assert(i == service.getTableDim() - 1 ? result : !result);
		}
		// cleanup column
		for (int i = 0; i < service.getTableDim(); i++)
		{
			service.makeAMove(i, j, CellState::Unoccupied);
		}
	}

	// check main diagonal
	for (int i = 0; i < service.getTableDim(); i++)
	{
		service.makeAMove(i, i, CellState::X);
		bool result = service.isThereAWinner();
		assert(i == service.getTableDim() - 1 ? result : !result);
	}
	// cleanup main diagonal
	for (int i = 0; i < service.getTableDim(); i++)
	{
		service.makeAMove(i, i, CellState::Unoccupied);
	}

	// check secondary diagonal
	for (int i = 0; i < service.getTableDim(); i++)
	{
		service.makeAMove(i, service.getTableDim() - i - 1, CellState::X);
		bool result = service.isThereAWinner();
		assert(i == service.getTableDim() - 1 ? result : !result);
	}
	// cleanup secondary diagonal
	for (int i = 0; i < service.getTableDim(); i++)
	{
		service.makeAMove(i, service.getTableDim() - i - 1, CellState::Unoccupied);
	}
}

void TestService::testMakeAMove()
{
	Repository repo(3);
	Service service(repo);

	service.makeAMove(0, 0, CellState::X);
	assert(service.get(0, 0) == CellState::X);
	service.makeAMove(0, 0, CellState::O);
	assert(service.get(0, 0) == CellState::O);
	service.makeAMove(0, 0, CellState::Unoccupied);
	assert(service.get(0, 0) == CellState::Unoccupied);

	try 
	{
		service.makeAMove(-1, 0, CellState::X);
		assert(false);
	}
	catch (RepositoryException & e) 
	{

	}
	catch (...)
	{
		assert(false);
	}

	try
	{
		service.makeAMove(0, -1, CellState::X);
		assert(false);
	}
	catch (RepositoryException & e)
	{

	}
	catch (...)
	{
		assert(false);
	}
	try 
	{
		service.makeAMove(-1, -1, CellState::X);
		assert(false);
	}
	catch (RepositoryException & e)
	{

	}
	catch (...) 
	{
		assert(false);
	}

	try 
	{
		service.makeAMove(0, 4, CellState::X);

		assert(false);
	}
	catch (RepositoryException & e)
	{

	}
	catch (...) 
	{
		assert(false);
	}

	try 
	{
		service.makeAMove(4, 0, CellState::X);
		assert(false);
	}
	catch (RepositoryException & e) 
	{

	}
	catch (...)
	{
		assert(false);
	}

	try
	{
		service.makeAMove(4, 4, CellState::X);
		assert(false);
	}
	catch (RepositoryException & e)
	{

	}
	catch (...) 
	{
		assert(false);
	}

	try 
	{
		service.makeAMove(-1, 4, CellState::X);
		assert(false);
	}
	catch (RepositoryException & e) 
	{

	}
	catch (...) 
	{
		assert(false);
	}
}

void TestService::testIsCellFree()
{
	Repository repo(3);
	Service service(repo);

	for (int i = 0; i < service.getTableDim(); i++)
	{
		for (int j = 0; j < service.getTableDim(); j++)
		{
			assert(service.isCellFree(i,j));
		}
	}

	service.makeAMove(1, 2, CellState::O);
	assert(!service.isCellFree(1, 2));
	service.makeAMove(1, 2, CellState::X);
	assert(!service.isCellFree(1, 2));
	service.makeAMove(1, 2, CellState::Unoccupied);
	assert(service.isCellFree(1, 2));
}

void TestService::testIsTableFull()
{
	Repository repo(3);
	Service service(repo);

	for (int i = 0; i < service.getTableDim(); i++)
	{
		for (int j = 0; j < service.getTableDim(); j++)
		{
			assert(!service.isTableFull());
			service.makeAMove(i, j, CellState::X);
		}
	}
	assert(service.isTableFull());
}

void TestService::runTestService()
{
	this->testGetTableDim();
	this->testGet();
	this->testIsThereAWinner();
	this->testMakeAMove();
	this->testIsCellFree();
	this->testIsTableFull();
}