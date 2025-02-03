#include <iostream>

// 상수 함수의 정확한 원리

class Point
{
	int x, y;
public:
	Point(int a , int b ) : x{a}, y{b} {}

//	void print() 		// void print(Point* this)
	void print() const	// void print(const Point* this)
	{	
	//	x = 10; // this->x = 10; 에서 this 가 const Point* 일때는 에러
	
		std::cout << x << ", " << y << std::endl;
	}
}; 
int main() 
{
	Point p1(1, 2);
	const Point p2(1, 2);

	p1.print();	// print(&p1) 입니다.	
	p2.print();	// print(&p2) 입니다.
				// print 가 const 가 아니면 "Point* this = &p2" 이므로 에러.
}

