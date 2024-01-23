#include "TestRepository.h"
#include "Repository.h"
#include <cassert>
#include "RepositoryException.h"

TestRepository::TestRepository()
{
}

TestRepository::~TestRepository()
{
}

void TestRepository::testInitData()
{
	Repository repository(3);
	for (int i = 0; i < repository.getTableDim(); i++)
	{
		for (int j = 0; j < repository.getTableDim(); j++)
		{
			assert(repository.get(i, j) == CellState::Unoccupied);
		}
	}
}

void TestRepository::testGetTableDim()
{
	Repository repository1;
	assert(repository1.getTableDim() == 0);
	Repository repository2(1);
	assert(repository2.getTableDim() == 1);
	Repository repository3(3);
	assert(repository3.getTableDim() == 3);
}

void TestRepository::testGet()
{
	Repository repository(3);
	try
	{
		assert(repository.get(0, 0) == CellState::Unoccupied);
		repository.update(0, 0, CellState::X);
		assert(repository.get(0, 0) == CellState::X);
	}
	catch (...) 
	{
		assert(false);
	}

	try
	{
		repository.get(-1, 0);
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
		repository.get(0, -1);
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
		repository.get(-1, -1);
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
		repository.get(0, 4);

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
		repository.get(4, 0);
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
		repository.get(4, 4);
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
		repository.get(-1, 4);
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

void TestRepository::testAdd()
{
	// nu putem testa, deoarece la initializarea repo-ului se umplu deja toate pozitiile posibile
}

void TestRepository::testUpdate()
{
	Repository repository(2);
	try
	{
		repository.update(1, 1, CellState::O);
		assert(repository.get(1, 1) == CellState::O);
	}
	catch (...) 
	{
		assert(false);
	}

	try 
	{
		repository.update(-1, 1, CellState::O);
	}
	catch (RepositoryException& e)
	{

	}
	catch (...)
	{
		assert(false);
	}

	try 
	{
		repository.update(1, -1, CellState::O);
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
		repository.update(-1, -1, CellState::O);
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
		repository.update(1, 3, CellState::O);
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
		repository.update(3, 1, CellState::O);
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
		repository.update(3, 3, CellState::O);
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
		repository.update(-1, 3, CellState::O);
	}
	catch (RepositoryException & e) 
	{

	}
	catch (...)
	{
		assert(false);
	}
}

void TestRepository::runTestRepository()
{
	this->testInitData();
	this->testGetTableDim();
	this->testGet();
	this->testAdd();
	this->testUpdate();
}