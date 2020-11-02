#include <iostream>
#include <algorithm>



int main()
{
	int size = 0;
	try
	{
		if((!std::cin >> size))
		{
			throw "invalid input data";
		}
		if (size <= 0)
		{
			throw "the size of array must be greater than zero";
		}
		int* A = new int[size];

		for (auto i = 0; i <= size; ++i)
		{
			if (i > size - 1 || i < 0)
			{
				delete A;
				throw "index out of range";
			}
			A[i] = i + 1;
		}
		delete A;
	}
	catch (const char* error)
	{
		std::cerr << "An error occured: " << error << std::endl;
		
	}

	std::cout << std::endl;
}
