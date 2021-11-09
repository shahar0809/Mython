#pragma once
#include <iostream>

class Type
{
public:
	Type();
	~Type();
	bool getIsTemp();
	void setIsTemp(bool isTemp);

	/*Virtual functions.*/
	virtual bool isPrintable() const = 0;
	virtual std::string toString() const = 0;

protected:
	bool _isTemp;

};

