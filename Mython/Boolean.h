#pragma once

#define TRUE "True"
#define FALSE "False"
#include "type.h"

class Boolean : public Type
{
private:
	bool _value;

public:
	Boolean(bool value);
	~Boolean();

	virtual bool isPrintable() const;
	virtual std::string toString() const;
	virtual Type* clone() const;
};

