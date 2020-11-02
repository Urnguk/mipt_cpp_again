#pragma once

#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>

const double pi = 3.14;

inline double distance(double x1, double y1, double x2, double y2)
{
	return pow(pow(x1 - x2, 2) + pow(y1 - y2, 2), 0.5);
}

class Shape
{
public:
	Shape() = default;
	virtual ~Shape() = default;

	friend std::ostream& operator<< (std::ostream& out, const Shape* shape);
protected:
	virtual double get_square() const = 0;
	virtual double get_perimeter() const = 0;
	virtual std::ostream& print(std::ostream& out) const = 0;
};

class Ellipse : public Shape
{
public:
	Ellipse(double a = 1, double b = 1, double x = 0, double y = 0);
	~Ellipse() = default;
private:
	double minor_semiaxis;
	double major_semiaxis;
protected:
	std::pair <double, double> center_point;

	virtual std::ostream& print(std::ostream& out) const override;

	virtual double get_square() const override
	{
		return pi * major_semiaxis * minor_semiaxis;
	}

	virtual double get_perimeter() const override
	{
		return 4 * (pi * minor_semiaxis * major_semiaxis + std::pow(major_semiaxis - minor_semiaxis, 2) / (major_semiaxis + minor_semiaxis));
	}
};

class Circle : public Ellipse
{
public:
	Circle(double r = 1, double x = 0, double y = 0);
	~Circle() = default;

private:
	double radius;
protected:
	virtual std::ostream& print(std::ostream& out) const override;

	virtual double get_square() const override
	{
		return pi * std::pow(radius, 2);
	}

	virtual double get_perimeter() const override
	{
		return 2 * pi * radius;
	}
};

class Polygon : public Shape
{
public:
	Polygon() = default;
	~Polygon() = default;
protected:
	std::vector <std::pair <double, double>> points;
};

class Triangle : public Polygon
{
public:
	Triangle(double x1 = 1, double y1 = 0, double x2 = 0, double y2 = 1, double x3 = 0, double y3 = 0);
	~Triangle() = default;
private:
	double a;
	double b;
	double c;
protected:
	virtual std::ostream& print(std::ostream& out) const override;

	virtual double get_perimeter() const override
	{
		return a+b+c;
	}

	virtual double get_square() const override
	{
		return std::pow(0.5 * get_perimeter() * (0.5 * get_perimeter() - a) * (0.5 * get_perimeter() - b) * (0.5 * get_perimeter() - c), 0.5);
	}
};

class Rectangle : public Polygon
{
public:
	Rectangle(double x1 = 0, double y1 = 0, double x2 = 2, double y2 = 0, double x3 = 2, double y3 = 1, double x4 = 0, double y4 = 1);
	~Rectangle() = default;
private:
	double length;
	double width;
protected:
	virtual std::ostream& print(std::ostream& out) const override;

	virtual double get_perimeter() const override
	{
		return 2 * (length + width);
	}

	virtual double get_square() const override
	{
		return length * width;
	}
};

class Square : public Rectangle
{
public:
	Square(double x1 = 0, double y1 = 0, double x2 = 1, double y2 = 0, double x3 = 1, double y3 = 1, double x4 = 0, double y4 = 1);
	~Square() = default;
private:
	double side;
protected:
	virtual std::ostream& print(std::ostream& out) const override;

	virtual double get_perimeter() const override
	{
		return 4 * side;
	}

	virtual double get_square() const override
	{
		return std::pow(side, 2);
	}
};
