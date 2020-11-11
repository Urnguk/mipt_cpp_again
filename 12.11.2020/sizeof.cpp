#include <iostream>

template <typename ... Types>
int weight(Types ... data)
{
	return (... + sizeof(data));
}

int weight_2()
{
	return 0;
}

template <typename Type, typename ... Types>
int weight_2(Type arg, Types ... data)
{
	return (sizeof(arg) + weight_2(data...));
}

int main()
{
	int x = 0;
	double y = 3.2;
	char c = '1';
	std::cout << weight(x, c ,y) << " = " << weight(x) << " + " << weight(c) << " + " << weight(y) << std::endl;
	std::cout << weight_2(x, c, y) << " = " << weight_2(x) << " + " << weight_2(c) << " + " << weight_2(y) << std::endl;
	return EXIT_SUCCESS;
}
