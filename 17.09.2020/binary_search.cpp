#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

int main()
{
	std::size_t size = 0;
	std::cout << "please enter the size of array:" << std::endl;
	std::cin >> size;

	std::vector <int> vec(size, 0);
	std::cout << "please enter the numbers in the array separated by space in any order (please take into account that currently our programm supports only integer values):" << std::endl;
	for (auto i = 0U; i < size; ++i)
	{
		std::cin >> vec[i];
	}

	sort(vec.begin(), vec.end());

	std::cout << "please enter the value to be found in this array:" << std::endl;
	int unknown = 0;
	std::cin >> unknown;

	int left = 0;
	int right = size - 1;
	int middle = 0;

	while (left <= right)
	{
		middle = (left + right) / 2;

		if (vec[middle] < unknown)
		{
			left = middle + 1;
		}

		else
		{
			if (vec[middle] > unknown)
			{
				right = middle - 1;
			}

			else
			{
				std::cout << "the " << unknown << " value was found" << std::endl;
				return 0;
			}
		}
	}

	std::cout << "the " << unknown << " value was not found" << std::endl;

	return 0;
}