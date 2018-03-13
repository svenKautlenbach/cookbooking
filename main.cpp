#include <iostream>


#include "for_each_custom.h"


int main(int argc, char* argv[])
{
	(void)argc;
	(void)argv;

	try
	{
		recipe_1_09::DummyCollection<std::string, 5> a{"yo", "tere", "123", "78", "."};

		for (const auto& aa : a)
		{
			std::cout << aa << std::endl;
		}
	}
	catch (const std::runtime_error& e)
	{
		std::cerr << "Caught runtime error: " << std::endl
				  << e.what() << std::endl;

		return 1;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Caught exception:" << std::endl
				  << e.what() << std::endl;
	}
	catch (...)
	{
		std::cerr << "Caught unknown object" << std::endl;
		return 3;
	}


	return 0;
}