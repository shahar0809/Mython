#pragma once
#include "type.h"
#include <string>

class Integer : public Type
{
private:
	int _value;

public:
	Integer(int value);
	~Integer();

	virtual bool isPrintable() const;
	virtual std::string toString() const;
};

