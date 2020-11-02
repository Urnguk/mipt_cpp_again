#include "shapes.hpp"

int main()
{
	auto array = new Shape * [5];
	array[0] = new Ellipse(2, 1);
	array[1] = new Circle(5, 0, 2.2);
	array[2] = new Triangle();
	array[3] = new Rectangle();
	array[4] = new Square(1,1,3,1,3,3,1,3);

	std::cout << array[0] << std::endl 
		<< array[1] << std::endl
		<< array[2] << std::endl
		<< array[3] << std::endl
		<< array[4] << std::endl;
	return EXIT_SUCCESS;
}
