#include "Container.hpp"

int main()
{
	Container <int> A(0);
	A.push(5, 0);
	A.set(3, 1);
	Container <int> B(1);
	B = A;
	std::cout << B.get(0) << " ";
	std::cout << B.pop(1) << " ";
	std::cout << B.pop(0);
}
