#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

int main()
{
	std::cout << "please, enter the size of array to be sorted:" << std::endl;
	int n = 0;
	std::cin >> n;

	std::cout << "please, enter the the numbert in the array, separated by space:" << std::endl;
	std::vector <int> array(n, 0);
	for (auto& element : array)
	{
		std::cin >> element;
	}

	std::cout << "please, enter 0 in case you'd like the array to be sorted in ascending order, otherwise please enter 1" 
		<< std::endl;
	bool flag = true;
	std::cin >> flag;

	if (flag)
	{
		std::sort(array.begin(), array.end(), [](int x, int y)
			{
				return x > y;
			});
	}
	else
	{
		std::sort(array.begin(), array.end(), [](int x, int y)
			{
				return x <= y;
			});
	}

	for (auto element : array)
	{
		std::cout << element << " ";
	}
	std::cout << std::endl;
}
