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
	for (auto i = 0U; i < vec.size(); ++i)
	{
		std::cin >> vec[i];
	}

	std::sort(vec.begin(), vec.end());

	std::cout << "please enter the value to be found in this array:" << std::endl;
	int unknown = 0;
	std::cin >> unknown;

	int left = 0;
	int right = size - 1;
	int middle = 0;
	bool flag = 1;

	while (left <= right && flag)
	{
		middle = left + (right - left)/2;

		if (vec[middle] == unknown)
		{
			flag = 0;
		}
		
		if (vec[middle] < unknown)
		{
			left = middle + 1;
		}

		else
		{
			right = middle - 1;
		}
	}

	if (flag)
	{
		std::cout << "the " << unknown << " value was not found" << std::endl;
	}
	
	else
	{
		std::cout << "the " << unknown << " value was found" << std::endl;
	}
	
	return 0;
}
