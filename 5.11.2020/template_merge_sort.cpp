#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>

const int N = 10;

/*template <typename T>
void print_array(T* array, std::size_t size)
{
	for (auto i = 0U; i < size; ++i)
	{
		std::cout << array[i] << " ";
	}
	std::cout << std::endl;
	return;
}*/

template <typename T, std::size_t size>
void print_array(T(&array)[size])
{
	for (auto i = 0U; i < size; ++i)
	{
		std::cout << array[i] << " ";
	}
	std::cout << std::endl;
	return;
}

/*template <typename T, typename F>
void merge_sort(T* array, std::size_t size, F cmp)
{
	T* copy = new T[size];

	for (auto i = 0U; i < size; ++i)
	{
		copy[i] = array[i];
	}


	split(copy, array, 0, size - 1, cmp);

	delete[] copy;
	return;
}*/

template <typename T, std::size_t size, typename F>
void merge_sort(T (&array) [size], F cmp)
{
	T copy [N];

	for (auto i = 0U; i < N; ++i)
	{
		copy[i] = array[i];
	}

	split(copy, array, 0, size - 1, cmp);

	return;
}

/*template <typename T, typename F>
void split(T* A, T* B, int left, int right, F cmp)
{
	if (left == right)
	{
		return;
	}

	int middle = (left + right) / 2;

	split(B, A, left, middle, cmp);
	split(B, A, middle + 1, right, cmp);

	merge(A, B, left, right, cmp);
	return;
}*/

template <typename T, std::size_t size, typename F>
void split(T(&A) [size], T (&B) [size], int left, int right, F cmp)
{
	if (left == right)
	{
		return;
	}

	int middle = (left + right) / 2;

	split(B, A, left, middle, cmp);
	split(B, A, middle + 1, right, cmp);

	merge(A, B, left, right, cmp);
	return;
}

/*template <typename T, typename F>
void merge(T* A, T* B, int left, int right, F cmp)
{
	int i = left;
	int middle = (left + right) / 2;
	int j = middle + 1;

	for (auto k = left; k <= right; ++k)
	{
		if (i <= middle && (j > right || cmp(A[i], A[j])))
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
	return;
}*/

template <typename T, std::size_t size, typename F>
void merge(T(&A)[size], T(&B)[size], int left, int right, F cmp)
{
	int i = left;
	int middle = (left + right) / 2;
	int j = middle + 1;

	for (auto k = left; k <= right; ++k)
	{
		if (i <= middle && (j > right || cmp(A[i], A[j])))
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
	return;
}

int main()
{
	double B[N];
//	int N = 0;
//	std::cin >> N;

//	int* A = new int[N];

	std::cout << "please, enter " << N << " numbers to be sorted, separated by space" << std::endl;


	for (auto i = 0U; i < N; ++i)
	{
		std::cin >> B[i];
	}

	char c = 'r';

	std::cout << "please, enter \'r\' symbol in case you'd like to sort the array in reversed order. Otherwise, please, enter any other symbol" << std::endl;

	std::cin >> c;

	if (c == 'r')
	{
		merge_sort(B, [](int x, int y) {return x > y; });
	}
	else
	{
		merge_sort(B, [](int x, int y) {return x < y; });
	}
	
	print_array(B);

//	delete[] A;
	return EXIT_SUCCESS;
}
