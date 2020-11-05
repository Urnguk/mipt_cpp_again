#include <iostream>
#include <vector>
#include <algorithm>
#include <type_traits>

using int_s = std::size_t;

template <typename T>
class Container
{
public:
	Container()
	{
		length = 0;
		data = nullptr;
		memory = false;
	}
	Container(T value)
	{
		length = 1;
		data = new T[length];
		data[0] = value;
		memory = true;
	}

	~Container()
	{
		if (memory)
		{
			delete[] data;
		}
	}

	void swap(int_s i, int_s j)
	{
		T tmp = data[i];
		data[i] = data[j];
		data[j] = tmp;
	}

	int size()
	{
		return length;
	}

	void push(T value, int_s index = length - 1)
	{
		resize(length + 1);
		data[length - 1] = value;
		for (auto i = length - 1; i > index; --i)
		{
			swap(i, i - 1);
		}
	}

	T pop(int_s index = length - 1)
	{
		T return_value = data[index];
		for (auto i = index; i < length - 1; ++i)
		{
			swap(i, i + 1);
		}
		resize(length - 1);
	}
protected:
	void resize(int_s size)
	{
		if (size != 0)
		{
			T* new_data = new T[size];
			for (auto i = 0; i < std::min(length, size); ++i)
			{
				new_data[i] = data[i];
			}
			delete[] data;
			data = new_data;
			memory = true;
			length = size;
		}
		else
		{
			delete[] data;
			length = 0;
			memory = false;
		}
	}
	
private:
	T* data;
	int_s length;
	bool memory;
};
