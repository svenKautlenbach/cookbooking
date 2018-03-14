#pragma once

namespace recipe_1_12
{
	namespace somelib
	{
#ifdef SOMELIB_VER_1
		inline namespace ver1
		{
			template<typename T>
			int test(T value) { (void)value; return 1; }
		}
#endif

#ifdef SOMELIB_VER_2
		inline namespace ver2
		{
			template<typename T>
			int test(T value) { return 2; }
		}
#endif
	}

	void run()
	{
		std::cout << somelib::test(6) << std::endl;
	}
}