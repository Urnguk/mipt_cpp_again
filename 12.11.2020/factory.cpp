#include <iostream>

class My_class
{
private:
	int m_x;
	double m_y;
	char m_c;
public:
	My_class(int x, double y, char c) : m_x(x), m_y(y), m_c(c) {}
	~My_class() = default;

	void print()
	{
		std::cout << m_x << " " << m_y << " " << m_c << std::endl;
	}

	void set_x(int value)
	{
		m_x = value;
	}
	void set_y(double value)
	{
		m_y = value;
	}
	void set_c(char value)
	{
		m_c = value;
	}
};

template <typename T, typename ... Types>
T* factory(Types... data)
{
	T* ret_value = new T(data...);
	return ret_value;
}

int main()
{
	My_class* example = factory<My_class>(3, 4.2, 'c');
	example->print();
	return EXIT_SUCCESS;
}
