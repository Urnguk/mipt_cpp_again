#include <iostream>

class My_class
{
public:
	virtual ~My_class() = default;

	virtual void print()
	{
		std::cout << "My class was printed" << std::endl;
	}
};

class My_special_class : public My_class
{
public:
	virtual ~My_special_class() = default;

	virtual void print() override
	{
		std::cout << "My special class was printed" << std::endl;
	}
};

template <typename Type>
class Base
{
private:
	Type* Me()
	{
		return static_cast<Type*>(this);
	}
public:
	virtual ~Base() = default;
	void print()
	{
		Me()->print();
	}
};

class Heir : public Base<Heir>
{
public:
	virtual ~Heir() = default;
	void print()
	{
		std::cout << "Heir was printed" << std::endl;
	}
};

int main()
{
	My_class* A = new My_special_class();
	Base<Heir>* B = new Base<Heir>();

	A->print();
	B->print();

	delete A;
	delete B;
	return EXIT_SUCCESS;
}
