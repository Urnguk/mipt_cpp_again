#include <iostream>
#include <cmath>
#include <vector>

int main()
{
	std::size_t size;
	std::cout << "please enter the size of array to be sorted:" << std::endl;
	std::cin >> size;

	std::vector <int> vec(size, 0);
	std::cout << "please enter the numbers to be sorted separated by space (please take into account that currently our programm supports only integer values):" << std::endl;
	for (auto i = 0U; i < size; ++i)
	{
		std::cin >> vec[i];
	}

	for (auto i = 1U; i < size; ++i)
	{
		auto j = i;
		while ((j > 0) && (vec[j - 1] > vec[j]))
		{
			std::swap(vec[j], vec[j - 1]);
			--j;
		}
	}

	for (auto i = 0U; i < size; ++i)
	{
		std::cout << vec[i] << ' ';
	}
	std::cout << std::endl;

	return 0;
}