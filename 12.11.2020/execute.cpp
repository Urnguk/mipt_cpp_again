#include <iostream>

template <typename F, typename ... Types>
void execute(F foo, Types ... data)
{
	foo(data...);
}

template <typename T1, typename T2>
void print(T1 x, T2 y)
{
	std::cout << x << " " << y << std::endl;
}

int main()
{
	int a = 7;
	char b = 'b';
	execute(print<int, double>, a, 4.3);
	execute([](char c) {std::cout << c << std::endl; }, b);
	return EXIT_SUCCESS;
}
