#include <iostream>

class My_class
{
public:
	My_class() = default;
	~My_class() = default;

	virtual void print()
	{
		std::cout << "My class was printed" << std::endl;
	}
};

class My_special_class : public My_class
{
public:
	My_special_class() = default;
	~My_special_class() = default;

	virtual void print() override
	{
		std::cout << "My special class was printed" << std::endl;
	}
};

int main()
{
	My_class* A = new My_class();
	delete A;
	return EXIT_SUCCESS;
}
