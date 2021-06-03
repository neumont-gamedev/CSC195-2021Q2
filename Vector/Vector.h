#pragma once
#include <initializer_list>
#include <limits>

namespace nc
{
    template<typename T>
    class vector
    {
    public:
        vector() {}
        vector(size_t capacity);
        vector(const std::initializer_list<T>& ilist);
        vector(const vector& other);
        ~vector();

        vector& operator = (const vector& other);

        T& operator [] (size_t position) { return _elements[position]; }
        const T& operator [] (size_t position) const { return _elements[position]; }

        T& at(size_t position) { return _elements[position]; }
        const T& at(size_t position) const { return _elements[position]; }

        T& front()  { return _elements[0]; }
        T& back()   { return _elements[_size -1]; }

        T* data()   { return _elements; }

        void push_back(const T& value);
        void pop_back();

        void reserve(size_t capacity);
        void resize(size_t new_size, const T& value = T{});
        void clear();

        void swap(vector& other);

        bool empty() const      { return _size == 0; }
        size_t size() const     { return _size; }
        size_t capacity() const { return _capacity; }
        size_t max_size() const { return std::numeric_limits<size_t>::max() / sizeof(T); }

    private:
        T* _elements = nullptr;
        size_t _size{};
        size_t _capacity{};
    };

    template<typename T>
    vector<T>::vector(size_t capacity)
    {
        _elements = new T[capacity];
        _capacity = capacity;
    }

    template<typename T>
    vector<T>::vector(const std::initializer_list<T>& ilist)
    {
        _size = ilist.size();
        _capacity = ilist.size();
        _elements = new T[_capacity];

        size_t i = 0;
        for (auto iter = ilist.begin(); iter != ilist.end(); iter++)
        {
            _elements[i] = *iter;
            i++;
        }
    }

    template<typename T>
    vector<T>::vector(const vector& other)
    {
        _size = other._size;
        _capacity = other._capacity;
        _elements = new T[_capacity];

        for (size_t i = 0; i < _size; i++)
        {
            _elements[i] = other._elements[i];
        }
    }

    template<typename T>
    vector<T>::~vector()
    {
        if (_elements)
        {
            delete[] _elements;
        }
    }

    template<typename T>
    vector<T>& vector<T>::operator = (const vector& other)
    {
        if (this == &other) return *this;

        if (_elements)
        {
            delete[] _elements;
        }

        _size = other._size;
        _capacity = other._capacity;
        _elements = new T[_capacity];

        for (size_t i = 0; i < _size; i++)
        {
            _elements[i] = other._elements[i];
        }

        return *this;
    }

    template<typename T>
    void vector<T>::push_back(const T& value)
    {
        if (_size == _capacity)
        {
            reserve(_capacity + 5);
        }

        _elements[_size] = value;
        _size++;
    }

    template<typename T>
    void vector<T>::pop_back()
    {
        if (_size > 0) _size--;
    }

    template<typename T>
    void vector<T>::reserve(size_t capacity)
    {
        if (capacity <= _capacity) return;

        T* new_elements = new T[capacity];
        for (size_t i = 0; i < _size; i++)
        {
            new_elements[i] = _elements[i];
        }
        delete[] _elements;

        _elements = new_elements;
        _capacity = capacity;
    }

    template<typename T>
    void vector<T>::resize(size_t new_size, const T& value)
    {
        if (new_size > _size)
        {
            if (new_size > _capacity)
            {
                reserve(new_size);
            }

            for (size_t i = _size; i < new_size; i++)
            {
                _elements[i] = value;
            }
        }

        _size = new_size;
    }

    template<typename T>
    void vector<T>::clear()
    {
        if (_elements)
        {
            delete[] _elements;
        }

        _elements = nullptr;
        _size = 0;
        _capacity = 0;
    }

    template<typename T>
    void vector<T>::swap(vector& other)
    {
        T* temp_elements = _elements;
        size_t temp_size = _size;
        size_t temp_capacity = _capacity;

        _elements = other._elements;
        _size = other._size;
        _capacity = other._capacity;

        other._elements = temp_elements;
        other._size = temp_size;
        other._capacity = temp_capacity;
    }
}
