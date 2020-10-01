#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>

typedef unsigned int ui_t;

struct Calendar
{
	Calendar(ui_t d, ui_t mo, ui_t y, ui_t h, ui_t mi, ui_t s, ui_t ms) :
		milliseconds(ms), seconds(s), minutes(mi), hours(h), days(d - 1), months(mo - 1), years(y - 1)
	{}
	~Calendar() {}

	ui_t milliseconds : 10;
	ui_t seconds : 6;
	ui_t minutes : 6;
	ui_t hours : 5;
	ui_t days : 5;
	ui_t months : 4;
	ui_t years : 28;
};

void print(const Calendar& date)
{
	std::cout << "the current date is: " << date.days + 1 << "." << date.months + 1 << "." << date.years + 1 << std::endl
		<< "the current time is: " << date.hours << ":" << date.minutes << ":" 
		<< date.seconds << "." << date.milliseconds << std::endl;
}

inline void incrementation(ui_t& a, ui_t& b, ui_t limit)
{
	if (a >= limit)
	{
		b += a / limit;
		a %= limit;
	}
}

void date_correction(ui_t& ms, ui_t& s, ui_t& mi, ui_t& h, ui_t& d, ui_t& mo, ui_t& y)
{
	incrementation(ms, s, 1000);
	incrementation(s, mi, 60);
	incrementation(mi, h, 60);
	incrementation(h, d, 24);
	incrementation(d, mo, 31);
	incrementation(mo, y, 12);
}

int main()
{
	ui_t day = 1;
	ui_t month = 1;
	ui_t year = 1;

	ui_t hour = 0;
	ui_t minute = 0;
	ui_t second = 0;
	ui_t millisecond = 0;

	std::string full_second;

	std::cout << "Please, enter the current date, with day, month and year separated by space:" << std::endl;
	std::cin >> day >> month >> year;
	std::cout << "Please, enter the current time, with hour, minute and second separated by space. Take into account"
		<< "that our programm can save seconds with accuracy to the third decimal place:" << std::endl;
	std::cin >> hour >> minute >> full_second;
	
	second = std::stoi(full_second.substr(0, full_second.find(".")));
	full_second.erase(0, full_second.find(".") + 1);
	millisecond = std::stoi(full_second);

	date_correction(millisecond, second, minute, hour, day, month, year);
	Calendar current(day, month, year, hour, minute, second, millisecond);
	print(current);

	return EXIT_SUCCESS;
}
