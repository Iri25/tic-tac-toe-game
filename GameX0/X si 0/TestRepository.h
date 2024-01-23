#pragma once

class TestRepository
{
private:
	void testInitData();

	void testGetTableDim();
	void testGet();

	void testAdd();
	void testUpdate();
public:
	TestRepository();
	~TestRepository();

	void runTestRepository();
};