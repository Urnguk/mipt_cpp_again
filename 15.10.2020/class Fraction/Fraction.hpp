#pragma once

#include <iostream>

int greatest_common_divisor(int x, int y);


class Fraction
{
public:
	Fraction(int x = 0, int y = 1);
	~Fraction() = default;

	int get_numerator() const { return numerator; }
	int get_denominator() const { return denominator;	}
	void set_numerator(int x);
	void set_denominator(int y);

	Fraction& operator++();
	Fraction operator++(int);
	Fraction& operator--();
	Fraction operator--(int);

	Fraction& operator+=(const Fraction& other);
	Fraction& operator-=(const Fraction& other);
	Fraction& operator*=(const Fraction& other);
	Fraction& operator/=(const Fraction& other);

	friend Fraction operator+(const Fraction& frac_1, const Fraction& frac_2);
	friend Fraction operator-(const Fraction& frac_1, const Fraction& frac_2);
	friend Fraction operator*(const Fraction& frac_1, const Fraction& frac_2);
	friend Fraction operator/(const Fraction& frac_1, const Fraction& frac_2);

	friend bool operator==(const Fraction& frac_1, const Fraction& frac_2);
	friend bool operator!=(const Fraction& frac_1, const Fraction& frac_2);
	friend bool operator<=(const Fraction& frac_1, const Fraction& frac_2);
	friend bool operator>=(const Fraction& frac_1, const Fraction& frac_2);
	friend bool operator<(const Fraction& frac_1, const Fraction& frac_2);
	friend bool operator>(const Fraction& frac_1, const Fraction& frac_2);


	friend std::ostream& operator<< (std::ostream& out, const Fraction& fraction);
	friend std::istream& operator>> (std::istream& in, Fraction& fraction);

	explicit operator double() const { return static_cast<double>(numerator) / denominator; }

private:
	int numerator;
	int denominator;

	void reduction();
};
