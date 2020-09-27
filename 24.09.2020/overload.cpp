#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

void f_1(int x) 
{
	std::cout << "F" << std::endl;
}

void f_1(int x, int y = 3)
{
	std::cout << "F" << std::endl;
}

void f_2(double x)
{
	std::cout << "F" << std::endl;
}

void f_2(long x)
{
	std::cout << "F" << std::endl;
}

void f_3(int x)
{
	std::cout << "F" << std::endl;
}


void f_3(int & x)
{
	std::cout << "F" << std::endl;
}



int main()
{
	int z = 1;
	f_1(z);
	f_2(z);
	f_3(z);

	return 0;
}
