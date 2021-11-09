#pragma once

#include "InterperterException.h"

class IndentationException : public InterperterException
{
public:
	virtual const char* what() const throw();
};



