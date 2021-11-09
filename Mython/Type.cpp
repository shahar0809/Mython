#include "type.h"

Type::Type()
{
	this->_isTemp = false;
}

Type::~Type()
{

}

void Type::setIsTemp(bool isTemp)
{
	this->_isTemp = isTemp;
}

bool Type::getIsTemp()
{
	return this->_isTemp;
}