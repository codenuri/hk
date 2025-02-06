#include <iostream>

class Point 
{
public:	
	int x, y;

	Point() 			: x{0}, y{0} {}	// 1
	Point(int x, int y) : x{x}, y{y} {}	// 2

	// 복사생성자
	// => 인자로 자신과 동일한 타입의 객체를 한개 받는 생성자
	// => 사용자가 만들지 않으면 컴파일러가 아래 모양으로 제공
	// => 컴파일러가 만든 복사 생성자는 "모든 멤버를 복사" 합니다.
	Point(const Point& other) : x{other.x}, y{other.y} {} 
};

int main()
{
	Point p1;		// ok. 1번 생성자 호출
	Point p2{1, 1};	// ok. 2번 생성자 호출

//	Point p3{1};	// error. 인자가 int 한개인 생성자는 없습니다

	Point p4{p2};	// ok. Point(Point) 모양의 생성자가 필요 합니다.
					// => 복사생성자라고 하고
					// => 사용자가 만들지 않으면 컴파일러가 만들어 줍니다.
	Point p5 = p2;  // ok. 복사 생성자 

	std::cout << p4.x << ", " << p4.y << std::endl;
}