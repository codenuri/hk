#include <iostream>

class Point
{
	int x;
	int y;
public:
	Point() 		    { x = 0; y = 0; std::cout << "Point()" << std::endl; } // 1
	Point(int a, int b) { x = a; y = b; std::cout << "Point(int, int)" << std::endl; } // 2
};

class Rect
{
	Point leftTop;
	Point rightBottom;
public:
	Rect()
	{
		// 컴파일러가 멤버 데이타의 생성자 호출 코드는 제일 위에 만들어 줍니다.
		// 항상 인자 없는 생성자 호출
		// call Point::Point() // leftTop 에 대해서
		// call Point::Point() // rightBottom 에 대해서
		
		std::cout << "Rect()" << std::endl;
	}
};

int main()
{
	Rect rc; 	// 1. sizeof(rc) 크기의 메모리를 스택에 할당당
				// 2. call Rect::Rect() 생성자 호출
}
