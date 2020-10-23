#include "Fraction.hpp"

int main()
{
	Fraction a(3);
	Fraction b(2, -4);
	a++;
	b++;
	std::cout << a << std::endl << b << std::endl;
	return EXIT_SUCCESS;
}
