#include <iostream>

class Grantor 
{
public:
	Grantor(int v1 = 0, int v2 = 0) : open_value(v1), close_value(v2) {}
	~Grantor() = default;

	void set(int x = 0, int y = 0) { 
		open_value = x;
		close_value = y;
	}

	friend class Attorney;

private:
	int open_value;
	int close_value;
	
};

class Attorney
{
public:
	Attorney() = default;
	~Attorney() = default;

private:
	inline static int get(Grantor& grantor)
	{
		return grantor.open_value;
	}

	friend class Friend;
};

class Friend 
{
public:
	Friend(int v = 0) : value(v) {}
	~Friend() = default;

	void get_value(Grantor& grantor)
	{
		value = Attorney::get(grantor);
	}

	int return_value()
	{
		return value;
	}

private:
	int value;
};

int main()
{
	Grantor A;
	Friend B(3);
	

	std::cout << B.return_value() << std::endl;

	B.get_value(A);
	std::cout << B.return_value() << std::endl;

	return EXIT_SUCCESS;
}
