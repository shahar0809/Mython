#pragma once
#include <iostream>
#include "InterperterException.h"

class NameErrorException : public InterperterException
{
public:
	NameErrorException(std::string name);
	virtual const char* what() const throw();

private:
	std::string _name;
};