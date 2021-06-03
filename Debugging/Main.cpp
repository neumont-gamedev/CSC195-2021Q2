#include <iostream>
#include <cassert>
#include <memory>

void func2(int i);

void func1()
{
	std::cout << "func1\n";
	func2(5);
}

void func2(int i)
{
	int j = i;
	std::cout << j << std::endl;
}

constexpr int sqr(int v)
{
	return v * v;
}

constexpr int factorial(int n)
{
	return n <= 1 ? 1 : (n * factorial(n - 1));
}

void int_to_ascii(int c)
{
	if (c > std::numeric_limits<char>::max())
	{
		throw std::invalid_argument("Value too large");
	}
}

template<typename T>
T divide(T a, T b)
{
	if (b == 0)
	{
		throw std::invalid_argument("Divide by zero");
	}

	return a / b;
}

int at(int* array, int index)
{
	if (index < 0)
	{
		throw std::out_of_range("Index out of range");
	}

	return *(array + index);
}

int main()
{
	// assert
	int i = 5;
	int* p = &i;
	//p = nullptr;

	assert(p);
	assert(i == 5);

	// static assert
	static_assert(sizeof(int*) == 4, "64-bit pointer size is not supported");
	static_assert(std::is_copy_constructible<std::shared_ptr<int>>::value, "does not support copy");

	// const expr(ession)
	const int j = 5;
	static_assert(sqr(j) == 25, "invalid sqr result");

	int a[4] = { 1, 2, 3, 4 };

	// exceptions handling
	try
	{
		int_to_ascii(127); //cause an exception to throw
		divide(10, 2);

		std::cout << at(a, -3) << std::endl;
		//p = nullptr;
		//int k = *p;
	}

	catch (std::invalid_argument& e)
	{
		std::cerr << "invalid arguement: " << e.what() << std::endl;
		//return -1;
	}
	catch (std::out_of_range& e)
	{
		std::cerr << "out of range: " << e.what() << std::endl;
		//return -1;
	}
	catch (std::exception& e)
	{
		std::cerr << "exception: " << e.what() << std::endl;
		//return -1;
	}

	std::cout << "continue\n";
}
