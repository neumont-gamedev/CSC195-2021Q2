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
	Point<int> pt1{ 10, 12 };
	Point<int> pt2;
	pt2 = pt1;
	std::cout << pt1 << std::endl;

	Point<float> pt3{ 23.5f, 12.5f };
	Point<float> pt4{ 4.25f, 2.15f };
	std::cout << (pt3 + pt4) << std::endl;
	
	float f{};
	std::cout << f << std::endl;

	std::cout << max(10, 14) << std::endl;
	std::cout << max(15.0f, 12.0f) << std::endl;

	std::cout << sqr(5) << std::endl;
	std::string text = "Hi!";
	std::cout << sqr(text) << std::endl;
}