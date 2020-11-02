#include <iostream>
#include <algorithm>



int main()
{
	int size = 0;
	try
	{
		std::cin >> size;
		if (size <= 0)
		{
			throw size;
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
	catch (int)
	{
		std::cerr << "An error occured: the size of array must be greater than zero" << std::endl;
	}

	std::cout << std::endl;
}
