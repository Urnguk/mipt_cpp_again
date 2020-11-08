#include <iostream>
#include <vector>
#include <algorithm>
#include <type_traits>



template <typename T>
class Container
{
public:
	
	using size_type = std::size_t;
	using index_type = unsigned int;
	using value_type = T;

	using array_reference = Container<T>&;
	using const_array_reference = const Container<T>&;

	using pointer = T*;
	using const_pointer = const T*;


	Container() : m_length(0), m_data(nullptr) {}
	Container(value_type value) : m_length(1)
	{
		m_data = new value_type[m_length];
		m_data[0] = value;
	}
	Container(const_pointer array, size_type N) : m_length(N)
	{
		if (m_length)
		{
			m_data = new value_type[m_length];
			for (index_type i = 0U; i < m_length; ++i)
			{
				m_data[i] = array[i];
			}
		}
		else 
		{
			m_data = nullptr;
		}
		
	}
	Container(const_array_reference container) : m_length(container.size()), m_data(new value_type[m_length])
	{
		if (m_length)
		{
			m_data = new value_type[m_length];
				for (index_type i = 0U; i < m_length; ++i)
				{
					m_data[i] = container.m_data[i];
				}
		}
		else
		{
			m_data = nullptr;
		}
	}
	Container(Container&& container) : m_length(container.size()), m_data(container.data)
	{
		container.m_data = nullptr;
		container.m_length = 0;
	}

	~Container()
	{
		delete[] m_data;
	}

	Container& operator= (const_array_reference container)
	{
		if (this == &container)
		{
			return *this;
		}

		delete[] m_data;

		m_length = container.m_length;

		if (m_length)
		{
			m_data = new value_type[m_length];
			for (index_type i = 0U; i < m_length; ++i)
			{
				m_data[i] = container.m_data[i];
			}
		}
		else
		{
			m_data = nullptr;
		}
		
		return *this;
	}

	Container& operator= (Container&& container)
	{
		if (this == &container)
		{
			return *this;
		}

		
		delete[] m_data;

		m_length = container.m_length;
		m_data = container.m_data;
	
		container.m_length = 0;
		container.m_data = nullptr;

		return *this;
	}

	friend bool operator== (const_array_reference container_1, const_array_reference container_2)
	{
		if (container_1.m_length == container_2.m_length)
		{
			for (index_type i = 0U; i < container_1.m_length; ++i) {
				if (container_1.m_data[i] != container_2.m_data[i])
				{
					return false;
				}
			}
			return true;
		}
		return false;
	}

	value_type operator[] (index_type index) const
	{
		return m_data[index];
	}

	value_type& operator[] (index_type index)
	{
		return m_data[index];
	}

	void swap_elements(index_type i, index_type j)
	{
		std::swap(m_data[i], m_data[j]);
	}

	void swap(array_reference other)
	{
		std::swap(other.m_length, m_length);
		std::swap(other.m_data, m_data);
	}

	friend void swap(array_reference container_1, array_reference container_2)
	{
		container_1.swap(container_2);
	}

	size_type size() const
	{
		return m_length;
	}

	void resize(index_type size)
	{
		if (size > 0)
		{
			pointer new_data = new value_type[size];
			for (index_type i = 0; i < std::min(m_length, size); ++i)
			{
				new_data[i] = m_data[i];
			}
			delete[] m_data;

			m_data = new_data;
			m_length = size;

			new_data = nullptr;
		}
		else
		{
			delete[] m_data;
			m_length = 0;
			m_data = nullptr;
		}
	}
	
private:
	pointer m_data;
	size_type m_length;
};
