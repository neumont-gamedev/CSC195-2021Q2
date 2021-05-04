#pragma once
#include <initializer_list>

namespace nc
{
	template<typename T, size_t Size>
	class array
	{
	public:
		array() {}
		array(const std::initializer_list<T>& ilist);

		T& operator [] (size_t position)				{ return m_elements[position]; }
		const T& operator [] (size_t position) const	{ return m_elements[position]; }
		T& at(size_t position)							{ return m_elements[position]; }
		const T& at(size_t position) const				{ return m_elements[position]; }

		T& front()	{ return m_elements[0]; }
		T& back()	{ return m_elements[size() - 1]; }

		T* data()	{ return m_elements; }

		void fill(T value);
		void swap(array& other);

		bool empty() const { return m_size == 0; }
		size_t size() const { return m_size; }

	private:
		size_t m_size = Size;
		T m_elements[Size]{};
	};

	template<typename T, size_t Size>
	array<T, Size>::array(const std::initializer_list<T>& ilist)
	{
		size_t i = 0;
		for (auto iter = ilist.begin(); iter != ilist.end(); iter++)
		{
			m_elements[i] = *iter;
			i++;
		}
	}

	template<typename T, size_t Size>
	void array<T, Size>::fill(T value)
	{
		for (size_t i = 0; i < size(); i++)
		{
			m_elements[i] = value;
		}
	}

	template<typename T, size_t Size>
	void array<T, Size>::swap(array& other)
	{
		for (size_t i = 0; i < size(); i++)
		{
			T temp = m_elements[i];
			m_elements[i] = other.m_elements[i];
			other.m_elements[i] = temp;
		}
	}
}
