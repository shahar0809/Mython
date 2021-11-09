#include "Void.h"

Void::Void() : Type()
{

}

Void::~Void()
{

}

bool Void::isPrintable() const
{
	return false;
}

std::string Void::toString() const
{
	return "";
}

Type* Void::clone() const
{
	return new Void(this);
}