#pragma once

class Point
{
public:
	Point() : x{0}, y{0} {}
	Point(int x, int y) : x{x}, y{y} {}

	//Point(const Point& point) { x = point.x; y = point.y; }

	Point& operator = (const Point& point) { x = point.x; y = point.y; return *this; }

	Point operator + (const Point& point) const { return Point{ x + point.x, y + point.y }; }
	bool operator == (const Point& point) const { return x == point.x && y == point.y; }

private:
	int x, y;
};

inline void func() {}