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
		
	}
	Container(T value)
	{
		length = 1;
		data = new T[length];
		data[0] = value;
		
	}
	Container(const Container <T>& container) : length(container.size())
	{
		if (length)
		{
			data = new T[length];
			for (auto i = 0U; i < length; ++i)
			{
				data[i] = container.data[i];
			}
		}
		else
		{
			data = nullptr;
		}
		
	}
	Container(Container <T>&& container) : length(container.size()), data(container.data)
	{
		container.data = nullptr;
	}

	~Container()
	{
		if (length)
		{
			delete[] data;
		}
	}

	Container <T>& operator= (const Container <T>& container)
	{
		if (this == &container)
		{
			return *this;
		}

		if (length)
		{
			delete[] data;
		}

		length = container.size();

		if (length)
		{
			data = new T[length];
			for (auto i = 0U; i < length; ++i)
			{
				data[i] = container.data[i];
			}
		}
		else
		{
			data = nullptr;
		}
		
		return *this;
	}

	Container <T>& operator= (Container <T>&& container)
	{
		if (this == &container)
		{
			return *this;
		}

		if (length)
		{
			delete[] data;
		}

		length = container.size();
		data = container.data;
		container.data = nullptr;

		return *this;
	}

	friend bool operator== (const Container <T>& container_1, const Container <T>& container_2)
	{
		if (container_1.length() == container_2.length())
		{
			for (auto i = 0U; i < container_1.length(); ++i) {
				if (container_1.get(i) != container_2.get(i))
				{
					return false;
				}
			}
			return true;
		}
		return false;
	}

	void swap(int_s i, int_s j)
	{
		T tmp = data[i];
		data[i] = data[j];
		data[j] = tmp;
	}

	int_s size() const
	{
		return length;
	}

	void push(T value, int_s index)
	{
		resize(length + 1);
		data[length - 1] = value;
		for (auto i = length - 1; i > index; --i)
		{
			swap(i, i - 1);
		}
	}

	T pop(int_s index)
	{
		T return_value = data[index];
		for (auto i = index; i < length - 1; ++i)
		{
			swap(i, i + 1);
		}
		resize(length - 1);
		return return_value;
	}

	T get(int_s index = 0)
	{
		return data[index];
	}

	void set(T value, int_s index = 0)
	{
		data[index] = value;
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
			length = size;
			new_data = nullptr;
		}
		else
		{
			delete[] data;
			length = 0;
			data = nullptr;
		}
	}
	
private:
	T* data;
	int_s length;
};
