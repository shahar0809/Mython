#pragma once
#include <iostream>
#include "InterperterException.h"

class NameErrorException : public InterperterException
{
public:
	virtual const char* what() const throw();

private:
	std::string _name;
};