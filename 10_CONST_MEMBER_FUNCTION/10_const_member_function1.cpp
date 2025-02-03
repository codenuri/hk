#include <iostream>

class Point
{
public:
	int x, y;

	Point(int a, int b ) : x{a}, y{b} {}

	void set(int a, int b) { x = a; y = b; }
	// 상수 멤버 함수 (const member function)
	// 1. 멤버 함수 안에서 멤버 데이타를 수정하지 않을것이라는 약속
	// 2. 데이타를 수정하는 코드가 있으면 에러
	// 3. 상수객체도 호출가능

//	void print()
	void print() const 
	{	
//		x = 100; // error. 상수 멤버함수안에서는 모든 멤버데이타는 상수

		std::cout << x << ", " << y << std::endl;
	}
}; 

int main() 
{
	const Point p(1, 2);

	p.x = 10;		// error. x 는 public 이지만 상수 이므로	
	p.set(10, 20);	// error.
	p.print();		// error.

	// #1. 상수 객체는 non-const 멤버 함수를 호출할수 없다.
	// #2. 상수 객체는 const 멤버 함수만 호출할수 있다.
}

