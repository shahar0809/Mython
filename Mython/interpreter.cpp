#include "type.h"
#include "parser.h"

#define WELCOME "Welcome to Magshimim Python Interperter version 1.0 by "
#define YOUR_NAME "Shahar Tefler"


int main(int argc,char **argv)
{
	std::cout << WELCOME << YOUR_NAME << std::endl;
	std::string s = "'";
	std::string input_string;

	// get new command from user
	std::cout << ">>> ";
	std::getline(std::cin, input_string);

	while (input_string != "quit()")
	{
		try
		{
			// prasing command
			Type* type = Parser::parseString(input_string);
			if (type->isPrintable())
			{
				std::cout << type->toString() << std::endl;
			}
			if (type->getIsTemp())
			{
				delete type;
			}
		}
		catch (const IndentationException& e)
		{
			std::cout << e.what() << std::endl;
		}
		catch (const SyntaxException & e)
		{
			std::cout << e.what() << std::endl;
		}

		// get new command from user
		std::cout << ">>> ";
		std::getline(std::cin, input_string);
	}

	Parser::freeMemory();
	return 0;
}
