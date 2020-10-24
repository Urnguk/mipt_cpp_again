#include <iostream>

int main() {
	
	double x;
	double y;
	
	std::cout << "Please, enter two numbers separated by a space. They'll be printed in reversed order.\n";
	std::cin >> x >> y;

	x += y;
	y = x - y;
	x = x - y;

	std::cout << x << ' ' << y << '\n';
	
	system("pause");
	return 0;
}