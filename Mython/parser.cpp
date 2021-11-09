#include "parser.h"

Type* Parser::parseString(std::string str) throw()
{
	Helper::removeLeadingZeros(str);

	/*Checking if the command starts with a space or a tab.*/
	if (str[0] == ' ' || str[0] == '\t')
	{
		throw(IndentationException());
	}

	if (isLegalVarName(str))
	{
		Type* varValue = getVariableValue(str);
		if (varValue != NULL && varValue->isPrintable())
		{
			std::cout << varValue->toString() << std::endl;
		}
	}
	
	Type* t = Parser::getType(str);
	if (t != NULL)
	{
		return t;
	}
	else if (makeAssignment(str))
	{
		Void* t = new Void();
		t->setIsTemp(true);
		return t;
	}
	else
	{
		throw NameErrorException(str);
	}
}

Type* Parser::getType(std::string& str)
{
	Type* type;
	if (Helper::isBoolean(str))
	{
		if (str.compare(TRUE))
		{
			type = new Boolean(true);
		}
		else
		{
			type = new Boolean(false);
		}
	}
	else if (Helper::isInteger(str))
	{
		type = new Integer(std::stoi(str));
	}
	else if (Helper::isString(str))
	{
		if (std::to_string(str[0]) == QUOTE)
		{
			str[0] = QUOTES, str[str.size() - 1] = QUOTES;
		}

		type = new String(str);
	}
	else
	{
		type = nullptr;
		throw(SyntaxException());
	}
	type->setIsTemp(true);
	return type;
}

bool Parser::isLegalVarName(const std::string& str)
{
	if (Helper::isDigit(str[0]))
		return false;

	for (int i = 0; i < str.size(); i++)
	{
		if (!Helper::isLetter(str[0]) && !Helper::isDigit(str[0]) && Helper::isUnderscore(str[0]))
		{
			return false;
		}
	}
	return true;
}

//bool Parser::isLegalVarName(const std::string& str)
//{
//	std::regex regexExpression("[\w_]+$");
//	return std::regex_match(str, regexExpression) && !std::isdigit(str[0]);
//}

bool Parser::makeAssignment(const std::string& str)
{
	if (str.find("=") != 1)
		return false;

	std::string varName = str.substr(0, str.find_first_of("="));
	std::string op = str.substr(str.find_first_of("=") + 1);

	// Remove whitespaces from variable name and value
	varName.erase(std::remove_if(varName.begin(), varName.end(), std::isspace), varName.end());
	op.erase(std::remove_if(op.begin(), op.end(), std::isspace), op.end());

	if (isLegalVarName(varName))
	{
		Type* valType = getType(op);
		Type* varValue = getVariableValue(op);

		if (isLegalVarName(op))
		{
			if (varValue)
			{
				m_map[varName] = varValue->clone();
			}
			else
			{
				throw NameErrorException(op);
			}
		}
		else if (valType)
		{
			m_map[varName] = valType;
		}
	}

	throw SyntaxException();
}

Type* Parser::getVariableValue(const std::string& str)
{
	if (!(m_map.find(str) == m_map.end()))
	{
		return NULL;
	}
	else
	{
		return m_map[str];
	}
}

void Parser::freeMemory()
{
	for (auto var = m_map.begin(); var != m_map.end(); var++)
	{
		if (var->second->getIsTemp())
		{
			delete var->second;
			m_map.erase(var->first);
		}
	}
}