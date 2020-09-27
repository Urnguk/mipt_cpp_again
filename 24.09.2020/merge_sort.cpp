#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

void print(std::vector <int> A)
{
	for (auto element : A)
	{
		std::cout << element << " ";
	}
	std::cout << std::endl;
	return;
}

void merge_sort(std::vector <int> & array, int left, int right);

void merge(std::vector <int>& array, int left, int right);

int main()
{
	int n = 1;
	std::cout << "please, enter the size of array to be sorted:" << std::endl;
	std::cin >> n;

	std::vector <int> array(n, 0);
	std::cout << "please, enter the numbers in the array, separated by space:" << std::endl;
	for (auto & element : array)
	{
		std::cin >> element;
	}

	

	merge_sort(array, 0, n - 1);

	print(array);

	return 0;
}

void merge_sort(std::vector <int>  & array, int left, int right)
{
	if (right == left)
	{
		return;
	}

	int middle = (left + right) / 2;

	merge_sort(array, left, middle);
	merge_sort(array, middle + 1, right);

	merge(array, left, right);

	return;
}

void merge(std::vector <int>& array, int left, int right)
{
	int middle = (left + right) / 2;

}
