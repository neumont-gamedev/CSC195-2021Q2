#pragma once
#include <initializer_list>
#include <limits>
#include <iostream>

namespace nc
{
	template<typename T>
	class list
	{
		struct node_t
		{
			node_t(const T& value) : _value{ value } {}

			T _value;
			node_t* _next{ nullptr };
			node_t* _prev{ nullptr };
		};

	public:
		list() {}
		list(const std::initializer_list<T>& ilist);
		list(const list& other);
		~list();

		list& operator = (const list& other);

		T& front() { return _head->_value; }
		const T& front() const { return _head->_value; }

		T& back() { return tail()->_value; }
		const T& back() const { return tail()->_value; }

		void push_front(const T& value);
		void pop_front();

		void push_back(const T& value);
		void pop_back();

		void remove(const T& value);
		void reverse();
		void resize(size_t count, const T& value = T{});
		void clear();

		bool empty() { return (_head == nullptr); }
		size_t size();
		size_t max_size() { return std::numeric_limits<size_t>::max(); }

		std::ostream& write(std::ostream& stream);

	private:
		node_t* tail();

	private:
		node_t* _head{ nullptr };
	};


	template<typename T>
	list<T>::list(const std::initializer_list<T>& ilist)
	{
		for (auto iter = ilist.begin(); iter != ilist.end(); iter++)
		{
			push_back(*iter);
		}
	}

	template<typename T>
	list<T>::list(const list& other)
	{
		node_t* node = other._head;
		while (node)
		{
			push_back(node->_value);
			node = node->_next;
		}
	}

	template<typename T>
	list<T>::~list()
	{
		clear();
	}

	template<typename T>
	list<T>& list<T>::operator = (const list& other)
	{
		clear();

		node_t* node = other._head;
		while (node)
		{
			push_back(node->_value);
			node = node->_next;
		}

		return *this;
	}

	template<typename T>
	void list<T>::push_front(const T& value)
	{
		node_t* new_node = new node_t{ value };
		if (_head)
		{
			_head->_prev = new_node;
		}
		new_node->_next = _head;
		_head = new_node;
	}

	template<typename T>
	void list<T>::pop_front()
	{
		if (_head)
		{
			node_t* temp_node = _head;
			_head = _head->_next;
			_head->_prev = nullptr;
			delete temp_node;
		}
	}

	template<typename T>
	void list<T>::push_back(const T& value)
	{
		node_t* new_node = new node_t{ value };
		if (_head == nullptr)
		{
			_head = new_node;
		}
		else
		{
			node_t* tail_node = tail();
			tail_node->_next = new_node;
			new_node->_prev = tail_node;
		}
	}

	template<typename T>
	void list<T>::pop_back()
	{
		node_t* tail_node = tail();
		if (tail_node)
		{
			node_t* prev_node = tail_node->_prev;
			if (prev_node) prev_node->_next = nullptr;
			if (tail_node == _head) _head = nullptr;

			delete tail_node;
		}
	}

	template<typename T>
	void list<T>::remove(const T& value)
	{
		node_t* node = _head;
		while (node)
		{
			if (node->_value == value)
			{
				node_t* next_node = node->_next;
				node_t* prev_node = node->_prev;
				if (prev_node) prev_node->_next = next_node;
				if (next_node) next_node->_prev = prev_node;

				if (_head == node)
				{
					_head = next_node;
				}
				delete node;
				node = next_node;
			}
			else
			{
				node = node->_next;
			}
		}
	}

	template<typename T>
	void list<T>::reverse()
	{
		node_t* node = _head;
		node_t* temp_node = nullptr;

		while (node)
		{
			temp_node = node->_prev;
			node->_prev = node->_next;
			node->_next = temp_node;
			node = node->_prev;
		}

		if (temp_node)
		{
			_head = temp_node->_prev;
		}
	}

	template<typename T>
	void list<T>::resize(size_t new_size, const T& value)
	{
		while (new_size < size())
		{
			pop_back();
		}
		while (new_size > size())
		{
			push_back(value);
		}
	}

	template<typename T>
	void list<T>::clear()
	{
		node_t* node = _head;
		while (node)
		{
			node_t* next_node = node->_next;
			delete node;
			node = next_node;
		}

		_head = nullptr;
	}

	template<typename T>
	size_t list<T>::size()
	{
		size_t size = 0;
		node_t* node = _head;
		while (node)
		{
			size++;
			node = node->_next;
		}

		return size;
	}

	template<typename T>
	std::ostream& list<T>::write(std::ostream& stream)
	{
		node_t* node = _head;
		while (node)
		{
			stream << node->_value << " ";
			node = node->_next;
		}
		stream << std::endl;

		return stream;
	}

	template<typename T>
	typename list<T>::node_t* list<T>::tail()
	{
		node_t* node = _head;
		while (node && node->_next)
		{
			node = node->_next;
		}

		return node;
	}
}
