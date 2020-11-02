#include "shapes.hpp"

std::ostream& operator<< (std::ostream& out, const Shape* shape)
{
	return shape->print(out);
}

Ellipse::Ellipse(double a, double b, double x, double y) :
	major_semiaxis(a), minor_semiaxis(b)
{
	center_point.first = x;
	center_point.second = y;
}

std::ostream& Ellipse::print(std::ostream& out) const
{
	out << "Center of this ellpise is located in the (" << center_point.first << " , " << center_point.second << ") point" << std::endl
		<< "the major semiaxis is equal to " << major_semiaxis << ", and the minor one - to " << minor_semiaxis << std::endl
		<< "the perimeter is approximately equal to " << get_perimeter() << ", ans square is equal to " << get_square() << std::endl;
	return out;
}


Circle::Circle(double r, double x, double y) : radius(r)
{
	center_point.first = x;
	center_point.second = y;
}

std::ostream& Circle::print(std::ostream& out) const
{
	out << "Center of this circle is located in the (" << center_point.first << " , " << center_point.second << ") point" << std::endl
		<< "the radius is equal to " << radius << std::endl
		<< "the perimeter is equal to " << get_perimeter() << ", ans square is equal to " << get_square() << std::endl;
	return out;
}


Triangle::Triangle(double x1, double y1, double x2, double y2, double x3, double y3) :
	a(distance(x1, y1, x2, y2)), b(distance(x1, y1, x3, y3)), c(distance(x3, y3, x2, y2))
{
	points.push_back(std::pair <double, double>(x1, y1));
	points.push_back(std::pair <double, double>(x2, y2));
	points.push_back(std::pair <double, double>(x3, y3));
}

std::ostream& Triangle::print(std::ostream& out) const
{
	out << "Points of this triangle are: (" << points[0].first << " , " << points[0].second << "), " 
		<< "(" << points[1].first << " , " << points[1].second << "), (" << points[2].first << " , " << points[2].second << ")" << std::endl
		<< "sides are equal to " << a << ", " << b << ", " << c << std::endl
		<< "the perimeter is equal to " << get_perimeter() << ", ans square is equal to " << get_square() << std::endl;
	return out;
}


Rectangle::Rectangle(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4) :
	length(std::max(distance(x1, y1, x2, y2), distance(x1, y1, x4, y4))), width(std::min(distance(x1, y1, x2, y2), distance(x1, y1, x4, y4)))
{
	points.push_back(std::pair <double, double>(x1, y1));
	points.push_back(std::pair <double, double>(x2, y2));
	points.push_back(std::pair <double, double>(x3, y3));
	points.push_back(std::pair <double, double>(x4, y4));
}

std::ostream& Rectangle::print(std::ostream& out) const
{
	out << "Points of this triangle are: (" << points[0].first << " , " << points[0].second << "), "
		<< "(" << points[1].first << " , " << points[1].second << "), (" << points[2].first << " , " << points[2].second << "), "
		<< "(" << points[3].first << " , " << points[3].second << ")"<< std::endl
		<< "length is equal to " << length << ", width is equal to " << width << std::endl
		<< "the perimeter is equal to " << get_perimeter() << ", ans square is equal to " << get_square() << std::endl;
	return out;
}


Square::Square(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4) : side(distance(x1, y1, x2, y2))
{
	points.push_back(std::pair <double, double>(x1, y1));
	points.push_back(std::pair <double, double>(x2, y2));
	points.push_back(std::pair <double, double>(x3, y3));
	points.push_back(std::pair <double, double>(x4, y4));
}

std::ostream& Square::print(std::ostream& out) const
{
	out << "Points of this triangle are: (" << points[0].first << " , " << points[0].second << "), "
		<< "(" << points[1].first << " , " << points[1].second << "), (" << points[2].first << " , " << points[2].second << "), "
		<< "(" << points[3].first << " , " << points[3].second << ")" << std::endl
		<< "side is equal to " << side << std::endl
		<< "the perimeter is equal to " << get_perimeter() << ", ans square is equal to " << get_square() << std::endl;
	return out;
}
