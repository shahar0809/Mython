#pragma once

#include "Boolean.h"
#include "SyntaxException.h"
#include "IndentationException.h"
#include "InterperterException.h"
#include "NameErrorException.h"
#include "type.h"
#include "Void.h"
#include "String.h"
#include "Helper.h"
#include <string>
#include <unordered_map>
#include <iostream>
#include <regex>
#include <algorithm>
#include <sstream>
#include "Integer.h"

#define TRUE "True"
#define QUOTES '"'
#define QUOTE "'"

class Parser
{
public:
	static Type* parseString(std::string str) throw();
	static Type* getType(std::string& str);
	static void freeMemory();

private:

	static bool isLegalVarName(const std::string& str);
	static bool makeAssignment(const std::string& str);
	static Type* getVariableValue(const std::string& str);

	static std::unordered_map<std::string, Type*> m_map;
};
