#include "Fraction.hpp"
#include <iostream>
#include <math.h>
#include <cassert>



int greatest_common_divisor(int x, int y)
{
	while (x != 0 && y != 0)
	{
		if (x > y)
		{
			x %= y;
		}
		else
		{
			y %= x;
		}
	}

	return (x + y);
}

Fraction::Fraction(int x, int y) :
	up(x), down(abs(y))
{
	assert(y != 0);
	if (y < 0)
	{
		up = -up;
	}
	reduction();
}

void Fraction::reduction()
{
	int divisor = greatest_common_divisor(abs(up), down);
	up /= divisor;
	down /= divisor;

	if (up == 0)
	{
		down = 1;
	}
}

Fraction& Fraction::operator++()
{
	up += down;
	reduction();
	return *this;
}
Fraction& Fraction::operator++(int)
{
	Fraction Temp(up, down);
	up += down;
	reduction();
	return Temp;
}

Fraction& Fraction::operator--()
{
	up -= down;
	reduction();
	return *this;
}
Fraction& Fraction::operator--(int)
{
	Fraction Temp(up, down);
	up -= down;
	reduction();
	return Temp;
}

std::ostream& operator<< (std::ostream& out, const Fraction& fraction)
{
	out << "dividend is " << fraction.up << " divider is " << fraction.down;
	return out;
}
