#pragma once

#include <iostream>

int greatest_common_divisor(int x, int y);


class Fraction
{
public:
	Fraction(int x = 0, int y = 1);
	~Fraction() = default;

	inline int get_up() const
	{
		return up;
	}
	inline unsigned int get_down() const
	{
		return down;
	}
	inline void set_up(int x)
	{
		up = x;
		reduction();
	}
	inline void set_down(unsigned int y)
	{
		down = y;
		reduction();
	}

	Fraction& operator++();
	Fraction& operator++(int);

	Fraction& operator--();
	Fraction& operator--(int);

	friend std::ostream& operator<< (std::ostream& out, const Fraction& fraction);

private:
	int up;
	unsigned int down;

	void reduction();
};
