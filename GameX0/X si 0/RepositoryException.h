#pragma once
#include <exception>
#include <string>

using namespace std;

class RepositoryException : public exception
{
private:
	char* message;
public:
	RepositoryException(const char* message)
	{
		this->message = new char[strlen(message) + 1];
		strcpy_s(this->message, strlen(message) + 1, message);
	}

	~RepositoryException()
	{
		if (this->message != NULL)
		{
			delete[] this->message;
		}
	}

	virtual const char* what()
	{
		return message;
	}
};