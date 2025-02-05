#include <iostream>
// 158 page ~
class Point
{
	int x, y;
public:
	Point(int x, int y) : x(x), y(y) {}

	void print() const 	{ std::cout << x << ", " << y << std::endl;	}

	// 멤버 함수로 만드는 operator+
	// 특징 : +는 이항연산자이지만 멤버로 만들면 인자가 1개 이다.
	// 주의 : 상수 객체라도 + 을 허용해야 한다. const member function
	Point operator+(const Point& pt) const  // operator+(const Point* this, const Point& pt)
	{	
		Point temp(x + pt.x, y + pt.y);		// Point temp(this->x + pt.x ...)
		return temp;
	}
};

int main()
{
	Point p1(1, 1);
	Point p2(2, 2);

	Point p3 = p1 + p2;	// 1. operator+(p1, p2) 또는
						// 2. p1.operator+(p2) 를 찾는다
	// p1.operator+(p2)
	// => operator+(&p1, p2)

	
}

