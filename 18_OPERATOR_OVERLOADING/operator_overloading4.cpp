#include <iostream>
// 158 page ~
class Point
{
	int x, y;
public:
	Point(int x, int y) : x(x), y(y) {}

	void print() const 	{ std::cout << x << ", " << y << std::endl;	}
	// 멤버 함수 버전과 일반 함수(non-member function) 버전을 동시에 제공하면
	// => 컴파일 에러!!
	// => 2개중 한개만 제공해야 합니다.
	Point operator+(const Point& pt) const 
	{	
		Point temp(x + pt.x, y + pt.y);
		return temp;
	}

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

	Point p3 = p1 + p2;	

	// 멤버가 좋을까 ? non-member 가 좋을까 ?
	// 멤버가 좋다는 주장 : private 멤버 데이타 접근이 편리하다.
	// non-member 주장 : 멤버로 할수 없을때 가 있다.
						// 멤버
	Point p4 = p1 + p2; // p1.operator+(Point)
	Point p5 = p1 + 3;	// p1.operator+(int)
	Point p6 = 3 + p1;  // 3.operator+(Point) => 멤버로 만들수 없다.
						// operator+(int, Point) => 이렇게는 된다.

	// 권장
	// +=, -= 등의 객체의 상태가 변하는 연산자 : 멤버 권장
	// +, -   등의 객체의 상태가 변하지 않은 연산자 : non-member 권장
}

