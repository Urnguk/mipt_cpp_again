#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <functional>

double calculate(double x, double y, std::function <double(double, double)> func)
{
	return func(x, y);
}

int main()
{
	std::vector <std::function <double(double, double)>> transformations;
	transformations.push_back([](double x, double y)
		{
			return x + y;
		});
	transformations.push_back([](double x, double y)
		{
			return x - y;
		});
	transformations.push_back([](double x, double y)
		{
			return x * y;
		});
	transformations.push_back([](double x, double y)
		{
			return x / y;
		});
	transformations.push_back([](double x, double y)
		{
			return std::pow(x, y);
		});
	transformations.push_back([](double x, double y)
		{
			double z = 1 / y;
			return std::pow(x, z);
		});

	std::cout << "please enter two numbers, separated by space:" << std::endl;
	double a = 0.0;
	double b = 0.0;
	std::cin >> a >> b;

	for (auto operation : transformations)
	{
		std::cout << calculate(a, b, operation) << " ";
	}
	std::cout << std::endl;
}
