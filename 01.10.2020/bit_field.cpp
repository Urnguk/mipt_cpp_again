#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>



struct Calendar
{
	Calendar(unsigned int day, unsigned int month, unsigned int year, unsigned int hour, unsigned int minute, unsigned int second, unsigned int millisecond) :
		milliseconds(millisecond), seconds(second), minutes(minute), hours(hour), days(day), months(month), years(year)
	{
		
	}
	~Calendar() {}

	unsigned int milliseconds : 10;
	unsigned int seconds : 6;
	unsigned int minutes : 6;
	unsigned int hours : 5;
	unsigned int days : 5;
	unsigned int months : 4;
	unsigned int years : 28;

};

void print(const Calendar& date)
{
	std::cout << "the current date is: " << date.days << "." << date.months << "." << date.years << std::endl
		<< "the current time is: " << date.hours << ":" << date.minutes << ":" << date.seconds << "." << date.milliseconds << std::endl;
}

void incrementation(unsigned int& a, unsigned int& b, unsigned int limit)
{
	if (a >= limit)
	{
		b += a / limit;
		a %= limit;
	}
}

int main()
{
	
	return EXIT_SUCCESS;
}
