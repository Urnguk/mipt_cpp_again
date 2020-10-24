#include "Fraction.hpp"
#include <iostream>
#include <math.h>
#include <algorithm>



int greatest_common_divisor(int x, int y)
{
	return (y == 0) ? x : greatest_common_divisor(y, x % y);
}

Fraction::Fraction(int x, int y) :
	numerator(x), denominator(abs(y))
{
	if (y == 0)
	{
		std::cerr << "Error: there was an attempt to divide by zero" << std::endl;
		abort();
	}
	if (y < 0)
	{
		numerator = -numerator;
	}
	reduction();
}

void Fraction::reduction()
{
	int divisor = greatest_common_divisor(abs(numerator), denominator);
	numerator /= divisor;
	denominator /= divisor;

	if (numerator == 0)
	{
		denominator = 1;
	}
}

void Fraction::set_numerator(int x)
{
	numerator = x;
	reduction();
}

void Fraction::set_denominator(int y)
{
	if (y == 0)
	{
		std::cerr << "Error: there was an attempt to divide by zero" << std::endl;
		abort();
	}
	if (y < 0)
	{
		numerator = -numerator;
	}
	denominator = abs(y);
	reduction();
}

Fraction& Fraction::operator++()
{
	numerator += denominator;
	return *this;
}
Fraction Fraction::operator++(int)
{
	Fraction Temp(*this);
	numerator += denominator;
	return Temp;
}

Fraction& Fraction::operator--()
{
	numerator -= denominator;
	return *this;
}
Fraction Fraction::operator--(int)
{
	Fraction Temp(*this);
	numerator -= denominator;
	return Temp;
}

Fraction& Fraction::operator+=(const Fraction& other)
{
	int divisor = greatest_common_divisor(denominator, other.denominator);

	numerator *= other.denominator / divisor;
	numerator += (denominator / divisor) * other.numerator;
	denominator *= other.denominator / divisor;

	reduction();

	return *this;
}

Fraction& Fraction::operator-=(const Fraction& other)
{
	int divisor = greatest_common_divisor(denominator, other.denominator);

	numerator *= other.denominator / divisor;
	numerator -= (denominator / divisor) * other.numerator;
	denominator *= other.denominator / divisor;

	reduction();

	return *this;
}

Fraction& Fraction::operator*=(const Fraction& other)
{
	numerator *= other.numerator;
	denominator *= other.denominator;

	reduction();

	return *this;
}

Fraction& Fraction::operator/=(const Fraction& other)
{

	numerator *= other.denominator;
	denominator *= other.numerator;

	if (denominator == 0)
	{
		std::cerr << "Error: there was an attempt to divide by zero" << std::endl;
		abort();
	}

	reduction();

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
	if (frac_1.numerator == frac_2.numerator && frac_1.denominator == frac_2.denominator)
	{
		return true;
	}
	return false;
}

bool operator!=(const Fraction& frac_1, const Fraction& frac_2)
{
	if (frac_1 == frac_2)
	{
		return false;
	}
	return true;
}

bool operator>(const Fraction& frac_1, const Fraction& frac_2)
{
	if (frac_1.numerator * frac_2.denominator > frac_2.numerator * frac_1.denominator)
	{
		return true;
	}
	return false;
}

bool operator>=(const Fraction& frac_1, const Fraction& frac_2)
{
	if (frac_1 > frac_2 || frac_1 == frac_2)
	{
		return true;
	}
	return false;
}

bool operator<(const Fraction& frac_1, const Fraction& frac_2)
{
	if (frac_1 >= frac_2)
	{
		return false;
	}
	return true;
}



bool operator<=(const Fraction& frac_1, const Fraction& frac_2)
{
	if (frac_1 > frac_2)
	{
		return false;
	}
	return true;
}

std::ostream& operator<< (std::ostream& out, const Fraction& fraction)
{
	out << "dividend is " << fraction.numerator << " divider is " << fraction.denominator;
	return out;
}

std::istream& operator>> (std::istream& in, Fraction& fraction)
{
	int x = 0;
	int y = 0;
	char c = '0';
	in >> x >> c >> y;
	fraction.set_numerator(x);
	fraction.set_denominator(y);
	fraction.reduction();
	return in;
}
