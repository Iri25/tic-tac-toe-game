#pragma once

class TestService 
{
private:
	void testGetTableDim();
	void testGet();

	void testIsThereAWinner();

	void testMakeAMove();

	void testIsCellFree();
	void testIsTableFull();
public:
	TestService();
	~TestService();

	void runTestService();
};