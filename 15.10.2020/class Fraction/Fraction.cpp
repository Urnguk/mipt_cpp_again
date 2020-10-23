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

Fraction::Fraction(const Fraction& frac) :
	up(frac.up), down(frac.down) {}

Fraction::Fraction(Fraction&& frac) :
	up(frac.up), down(frac.down) {}

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

void Fraction::set_up(int x)
{
	up = x;
	reduction();
}

void Fraction::set_down(int y)
{
	assert(y);
	if (y < 0)
	{
		up = -up;
	}
	down = abs(y);
	reduction();
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

Fraction& Fraction::operator+=(const Fraction& other)
{
	int divisor = greatest_common_divisor(down, other.down);

	up *= other.down / divisor;
	up += (down / divisor) * other.up;
	down *= other.down / divisor;

	reduction();

	return *this;
}

Fraction& Fraction::operator-=(const Fraction& other)
{
	int divisor = greatest_common_divisor(down, other.down);

	up *= other.down / divisor;
	up -= (down / divisor) * other.up;
	down *= other.down / divisor;

	reduction();

	return *this;
}

Fraction& Fraction::operator*=(const Fraction& other)
{
	up *= other.up;
	down *= other.down;

	reduction();

	return *this;
}

Fraction& Fraction::operator/=(const Fraction& other)
{
	assert(other.up);
	up *= other.down;
	down *= other.up;

	reduction();

	return *this;
}

Fraction& Fraction::operator=(const Fraction& other)
{
	if (*this == other)
	{
		return *this;
	}
	up = other.up;
	down = other.down;
	return *this;
}

Fraction& Fraction::operator=(const Fraction&& other)
{
	if (*this == other)
	{
		return *this;
	}
	up = other.up;
	down = other.down;
	return *this;
}

Fraction operator+(const Fraction& frac_1, const Fraction& frac_2)
{
	Fraction result(frac_1);
	result += frac_2;
	return result;
}

Fraction operator-(const Fraction& frac_1, const Fraction& frac_2)
{
	Fraction result(frac_1);
	result -= frac_2;
	return result;
}

Fraction operator*(const Fraction& frac_1, const Fraction& frac_2)
{
	Fraction result(frac_1);
	result *= frac_2;
	return result;
}

Fraction operator/(const Fraction& frac_1, const Fraction& frac_2)
{
	Fraction result(frac_1);
	result /= frac_2;
	return result;
}

bool operator==(const Fraction& frac_1, const Fraction& frac_2)
{
	if (frac_1.up == frac_2.up && frac_1.down == frac_2.down)
	{
		return true;
	}
	return false;
}

bool operator!=(const Fraction& frac_1, const Fraction& frac_2)
{
	if (frac_1.up == frac_2.up && frac_1.down == frac_2.down)
	{
		return false;
	}
	return true;
}

bool operator>=(const Fraction& frac_1, const Fraction& frac_2)
{
	int divisor = greatest_common_divisor(frac_1.down, frac_2.down);
	if ((frac_1.up * (frac_2.down/divisor) - frac_2.up * (frac_1.down / divisor)) >= 0)
	{
		return true;
	}
	return false;
}

bool operator<=(const Fraction& frac_1, const Fraction& frac_2)
{
	int divisor = greatest_common_divisor(frac_1.down, frac_2.down);
	if ((frac_1.up * (frac_2.down / divisor) - frac_2.up * (frac_1.down / divisor)) <= 0)
	{
		return true;
	}
	return false;
}

bool operator>(const Fraction& frac_1, const Fraction& frac_2)
{
	int divisor = greatest_common_divisor(frac_1.down, frac_2.down);
	if ((frac_1.up * (frac_2.down / divisor) - frac_2.up * (frac_1.down / divisor)) > 0)
	{
		return true;
	}
	return false;
}

bool operator<(const Fraction& frac_1, const Fraction& frac_2)
{
	int divisor = greatest_common_divisor(frac_1.down, frac_2.down);
	if ((frac_1.up * (frac_2.down / divisor) - frac_2.up * (frac_1.down / divisor)) < 0)
	{
		return true;
	}
	return false;
}

std::ostream& operator<< (std::ostream& out, const Fraction& fraction)
{
	out << "dividend is " << fraction.up << " divider is " << fraction.down;
	return out;
}

std::istream& operator>> (std::istream& in, Fraction& fraction)
{
	int x = 0;
	int y = 0;
	in >> x >> y;
	fraction.set_up(x);
	fraction.set_down(y);
	fraction.reduction();
	return in;
}
