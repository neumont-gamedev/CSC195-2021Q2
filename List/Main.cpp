#include "List.h"
#include <iostream>

class A
{
public:
	// default constuctor
	A() { std::cout << "constructor\n"; }

	// default destructor
	~A() { std::cout << "destructor\n"; }
	// default copy constructor
	A(const A& copy) { std::cout << "copy\n"; v = copy.v; }
	// default assignment operator
	//void operator = (const A& other) { v = other.v; std::cout << "assignment\n"; }
	A& operator = (const A& other) { std::cout << "assignment\n"; v = other.v; return *this; }

public:
	int v{};
};

int main()
{
	// default class methods
	{
		A a1;
		a1.v = 4;
		std::cout << a1.v << std::endl;

		A a2{ a1 };
		std::cout << a2.v << std::endl;
		a2.v = 6;

		A a3;
		a3 = a2;
		std::cout << a3.v << std::endl;
	}
	//a1.v = 4;

	// pointer arithmatic
	int array[] = { 5, 12, 17, 20 };
	std::cout << array << std::endl;
	//std::cout << *(array + 1) << std::endl;
	std::cout << array + 1 << std::endl;
	std::cout << array + 2 << std::endl;

	int* parray = array;
	for (size_t i = 0; i < 4; i++)
	{
		std::cout << *parray << std::endl;
		parray++;
	}

	// list
	std::cout << "list\n";
	nc::list<int> numbers{ 12, 78, 12, 34, 9 };
	numbers.push_back(10);
	numbers.push_front(8);
	numbers.write(std::cout);

	std::cout << "copy\n";
	nc::list<int> copy;
	copy = numbers;
	copy.pop_front();
	copy.pop_back();
	copy.pop_back();
	copy.write(std::cout);

	std::cout << "remove\n";
	copy.remove(12);
	copy.write(std::cout);

	std::cout << "resize\n";
	copy.resize(10, 99);
	copy.write(std::cout);

	std::cout << "reverse\n";
	numbers.reverse();
	numbers.write(std::cout);

	std::cout << "front: " << numbers.front() << std::endl;
	std::cout << "back: " << numbers.back() << std::endl;
	std::cout << "size: " << numbers.size() << std::endl;
	std::cout << "empty: " << numbers.empty() << std::endl;
}