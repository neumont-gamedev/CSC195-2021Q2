#include "Point.h"
#include <iostream>


//int max(int i1, int i2)
//{
//	return (i1 > i2) ? i1 : i2;
//}

template <typename T>
T max(T v1, T v2)
{
	return (v1 > v2) ? v1 : 2;
}

template <typename T>
T sqr(T v)
{
	return v * v;
}

template <>
std::string sqr(std::string s)
{
	return s + s;
}


int main()
{
	Point p1{ 10, 12 };
	Point p2;
	p2 = p1;


	std::cout << max(10, 14) << std::endl;
	std::cout << max(15.0f, 12.0f) << std::endl;

	std::cout << sqr(5) << std::endl;
	std::string text = "Hi!";
	std::cout << sqr(text) << std::endl;
}