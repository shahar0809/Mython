#include "Integer.h"

Integer::Integer(int value) : Type()
{
	this->_value = value;
}

Integer::~Integer()
{

}

bool Integer::isPrintable() const
{
	return true;
}

std::string Integer::toString() const
{
	return std::to_string(this->_value);
}