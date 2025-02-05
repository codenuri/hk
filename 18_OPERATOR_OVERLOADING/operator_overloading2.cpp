#include <iostream>
// 158 page ~
class Point
{
	int x, y;
public:
	Point(int x, int y) : x(x), y(y) {}

	void print() const 	{ std::cout << x << ", " << y << std::endl;	}


	friend Point operator+(const Point& p1, const Point& p2);
};
Point operator+(const Point& p1, const Point& p2)
{
	Point pt(p1.x + p2.x, p1.y + p2.y);
	return pt;
}

int main()
{
	Point p1(1, 1);
	Point p2(2, 2);

	Point p3 = p1 + p2;	// 1. operator+(p1, p2) 또는
						// 2. p1.operator+(p2) 를 찾는다

	Point p4 = operator+(p1, p2); // 이렇게 해도 됩니다.
}

