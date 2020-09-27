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

void split(std::vector <int> & A, std::vector <int> & B, int left, int right);

void merge(std::vector <int> & A, std::vector <int> & B, int left, int right);

int main()
{
	int n = 1;
	std::cout << "please, enter the size of array to be sorted:" << std::endl;
	std::cin >> n;

	std::vector <int> array(n, 0);
	std::cout << "please, enter the numbers in the array, separated by space:" << std::endl;
	for (auto& element : array)
	{
		std::cin >> element;
	}

	merge_sort(array, 0, n - 1);

	print(array);

	return 0;
}

void merge_sort(std::vector <int> & array, int left, int right)
{
	std::vector <int> copy(array.size(), 0);
	for (auto i = 0; i < array.size(); ++i)
	{
		copy[i] = array[i];
	}

	split(copy, array, left, right);

	return;
}

void split(std::vector <int> & A, std::vector <int> & B, int left, int right)
{
	if (left == right)
	{
		return;
	}
	
	int middle = (left + right) / 2;

	split(B, A, left, middle);
	split(B, A, middle + 1, right);

	merge(A, B, left, right);

	return;
}

void merge(std::vector <int> & A, std::vector <int> & B, int left, int right)
{
	int i = left;
	int middle = (left + right) / 2;
	int j = middle + 1;

	for (auto k = left; k <= right; ++k)
	{
		if (i <= middle && (j > right || A[i] <= A[j]))
		{
			B[k] = A[i];
			++i;
		}

		else
		{
			B[k] = A[j];
			++j;
		}
	}

}
