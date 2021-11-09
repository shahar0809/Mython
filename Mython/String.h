#pragma once
#include "type.h"

class String : public Type
{
private:
	std::string _value;

public:
	String(std::string value);
	~String();

	virtual bool isPrintable() const;
	virtual std::string toString() const;
};