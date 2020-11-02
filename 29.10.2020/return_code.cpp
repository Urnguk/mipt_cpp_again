#include <iostream>
#include <algorithm>

enum struct Error { Error_1, Error_2 };

union Result
{
	int value;
	Error error;
};

Result function(int arg)
{
	Result res;
	if (arg > 0)
	{
		res.error = Error::Error_1;
	}
	else
	{
		if (arg < 0)
		{
			res.error = Error::Error_2;
		}
		else
		{
			res.value = arg;
		}
	}

	return res;
}

int main()
{
	auto b = function(-1);
	if (b.error == Error::Error_1)
	{
		std::cerr << "Error 1 occured";
	}
	else
	{
		if (b.error == Error::Error_2)
		{
			std::cerr << "Error 2 occured";
		}
		else 
		{
			std::cout << b.value;
		}
	}
	
}
