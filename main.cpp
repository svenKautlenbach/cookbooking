#include <iostream>


#include "for_each_custom.h"

#define SOMELIB_VER_1
#include "inline_namespace.h"


int main(int argc, char* argv[])
{
	(void)argc;
	(void)argv;

	try
	{
		recipe_1_12::run();
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