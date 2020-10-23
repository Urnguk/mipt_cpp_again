#pragma once

#include <iostream>

int greatest_common_divisor(int x, int y);


class Fraction
{
public:
	Fraction(int x = 0, int y = 1);
	Fraction(const Fraction& fraction);
	Fraction(Fraction&& fraction);
	~Fraction() = default;

	inline int get_up() const
	{
		return up;
	}
	inline unsigned int get_down() const
	{
		return down;
	}
	void set_up(int x);
	void set_down(int y);

	Fraction& operator++();
	Fraction operator++(int);
	Fraction& operator--();
	Fraction operator--(int);

	Fraction& operator+=(const Fraction& other);
	Fraction& operator-=(const Fraction& other);
	Fraction& operator*=(const Fraction& other);
	Fraction& operator/=(const Fraction& other);

	Fraction& operator=(const Fraction& other);
	Fraction& operator=(const Fraction&& other);

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

	explicit operator double() const { return double(up) / double(down); }

private:
	int up;
	unsigned int down;

	void reduction();
};
