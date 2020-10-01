#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>

enum struct Month {January = 1, February, March, April, May, June, 
	July, August, September, October, November, December};
int amount_of_days()
{
	int number;
	std::cout << "please enter the number of month: " << std::endl;
	std::cin >> number;

	if (number < 1 || number > 12)
	{
		return -1;
	}

	Month month = static_cast<Month>(number);
	switch (month)
	{
	case Month::January:
	case Month::March:
	case Month::May:
	case Month::July:
	case Month::August:
	case Month::October:
	case Month::December:
		return 31;
	case Month::February:
		return 28;
	default:
		return 30;


	}
}

int main()
{
	std::cout << amount_of_days() << std::endl;

	return EXIT_SUCCESS;
}
