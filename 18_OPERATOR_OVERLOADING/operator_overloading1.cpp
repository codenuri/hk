#include <iostream>
// 158 page ~
class Point
{
	int x, y;
public:
	Point(int x, int y) : x(x), y(y) {}

	void print() const 	{ std::cout << x << ", " << y << std::endl;	}
};

int main()
{
	Point p1(1, 1);
	Point p2(2, 2);

	// 다음중 어떤 코드가 보기 좋을 까요 ?
	Point p3 = Add(p1, p2); 
	Point p4 = p1.Add(p2);	// java style		
	Point p5 = p1 + p2;		// 하지만 C++ 이렇게 사용할수 있게 하자는 철학

	// 연산자 재정의 : 사용자 정의 타입도 +, - 연산자를 사용할수 있게 하자

	Point p6 = p1 + p2;	// 1. operator+(p1, p2) 또는
						// 2. p1.operator+(p2) 를 찾는다

}

