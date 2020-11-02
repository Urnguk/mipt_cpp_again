#include "Fraction.hpp"

int main()
{
	try
	{
		Fraction a;
		std::cout << "please, enter a fraction" << std::endl;
		std::cin >> a;
		Fraction b = a++;
		if (a > b)
		{
			std::cout << a << std::endl;
		}
	}
	catch (int)
	{
		std::cerr << "Error: there was an attempt to divide by zero" << std::endl;
	}
	catch (const char* err)
	{
		std::cerr << "Error: " << err << std::endl;
	}

	return EXIT_SUCCESS;
}
