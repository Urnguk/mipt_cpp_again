#pragma once

#include <iostream>

int greatest_common_divisor(int x, int y);

class Fraction
{
public:
	explicit Fraction(int x = 0, int y = 1);
	Fraction(double x = 0.0, double y = 1.0);
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


private:
	int up;
	unsigned int down;

	void reduction();
};
