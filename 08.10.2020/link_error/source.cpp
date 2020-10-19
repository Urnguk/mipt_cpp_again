#include <iostream>
#include "header_1.hpp"
#include "header_2.hpp"

void f(int value)
{
	std::cout << value << std::endl;
	return;
}

int main()
{
	extern int x;
	extern int y;
	f(x);
	

	return EXIT_SUCCESS;
}
