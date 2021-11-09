#include "Boolean.h"

Boolean::Boolean(bool value) : Type()
{
	this->_value = value;
}

Boolean::~Boolean()
{

}

bool Boolean::isPrintable() const
{
	return true;
}

std::string Boolean::toString() const
{
	return this->_value ? "True" : "False";
}