#pragma once
#include <iostream>

template <typename T>
class Point
{
public:
	Point() : x{ T{} }, y{ T{} } {}
	Point(T x, T y) : x{x}, y{y} {}

	Point& operator = (const Point& point) { x = point.x; y = point.y; return *this; }

	Point operator + (const Point& point) const { return Point{ x + point.x, y + point.y }; }
	Point operator - (const Point& point) const { return Point{ x - point.x, y - point.y }; }

	Point& operator += (const Point& point) { x += point.x; y += point.y; return *this; }
	Point& operator -= (const Point& point) { x -= point.x; y -= point.y; return *this; }

	bool operator == (const Point& point) const { return x == point.x && y == point.y; }
	bool operator != (const Point& point) const { return !(*this == point); }

	friend std::ostream& operator << (std::ostream& ostream, const Point<T>& point)
	{
		ostream << point.x << " : " << point.y;
		return ostream;
	}

private:
	T x, y;
};

inline void func() {}