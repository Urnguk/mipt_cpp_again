#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

bool double_equal(double a, double b)
{
	return std::abs(a - b) <= std::numeric_limits <double> ::epsilon();
}

int main()
{
	std::size_t size = 0;
	std::cout << "please enter the number of equations to be solved:" << std::endl;
	std::cin >> size;

	double** matrix = new double* [size];
	for (auto i = 0U; i < size; ++i)
	{
		matrix[i] = new double[size + 1];
	}
	
	for (auto i = 0U; i < size; ++i)
	{
		std::cout << "please enter the coefficients of " << i + 1 << " equation separated by space:" << std::endl;
		for (auto j = 0U; j < size + 1; ++j)
		{
			std::cin >> matrix[i][j];
		}
	}

	std::vector <int> null;
	bool flag_zero = false;
	
	
	for (auto i = 0U; i < size - 1; ++i)
	{
		if (double_equal(matrix[i][i], 0.0))
		{
			auto j = i + 1;
			while (j < size && double_equal(matrix[j][i], 0.0))
			{
				++j;
			}

			if (j == size)
			{
				null.push_back(i);
				continue;
			}
			else
			{
				for (auto k = 0U; k < size + 1; ++k)
				{
					std::swap(matrix[i][k], matrix[j][k]);
				}
			}
		}

		for (auto l = i + 1; l < size; ++l)
		{
			double factor = matrix[l][i] / matrix[i][i];
			for (auto s = 0; s < size + 1; ++s)
			{
				matrix[l][s] -= matrix[i][s] * factor;
			}
		}
	}

	for (auto i = 1U; i < size; ++i)
	{
		if (double_equal(matrix[i][i], 0.0))
		{
			continue;
		}

		for (auto l = 0; l < i; ++l)
		{
			double factor = matrix[l][i] / matrix[i][i];
			for (auto s = 0; s < size + 1; ++s)
			{
				matrix[l][s] -= matrix[i][s] * factor;
			}
		}
	}

	if (null.size() > 0)
	{
		for (auto index : null)
		{
			if (! double_equal(matrix[index][size], 0.0))
			{
				flag_zero = true;
				break;
			}
		}

		if (flag_zero)
		{
			std::cout << "there are no roots of this system of equations" << std::endl;
		}
		else
		{
			std::cout << "there are an infinite number of roots of this system of equations" << std::endl;
		}
	}
	else
	{
		std::vector <double> result;
		for (auto i = 0U; i < size; ++i)
		{
			result.push_back(matrix[i][size] / matrix[i][i]);
		}
		std::cout << "the roots of this system of equations are: ";
		for (auto root : result)
		{
			std::cout << root << " ";
		}
		std::cout << std::endl;
	}

	for (auto i = 0U; i < size; ++i)
	{
		delete[] matrix[i];
	}
	delete[] matrix;

	return 0;
}