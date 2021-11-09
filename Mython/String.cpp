#include "String.h"

#include "String.h"

String::String(std::string value) : Type()
{
	this->_value = value;
}

String::~String()
{

}

bool String::isPrintable() const
{
	return true;
}

std::string String::toString() const
{
	std::string newStr = std::string(this->_value), temp = this->_value.substr(1, this->_value.size() - 2);

	if (temp.find('\'') != std::string::npos)
	{
		newStr[0] = '\"', newStr[newStr.size() - 1] = '\"';
	}
	else
	{
		newStr[0] = '\'', newStr[newStr.size() - 1] = '\'';
	}
	return newStr;
}

Type* String::clone() const
{
	return new String(this);
}