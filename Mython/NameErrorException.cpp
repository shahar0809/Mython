#include "NameErrorException.h"

NameErrorException::NameErrorException(std::string name)
{
	_name = name;
}

const char* NameErrorException::what() const throw()
{
	std::string error = "NameError : name " + this->_name + "is not defined.\n";
	return error.c_str();
}
