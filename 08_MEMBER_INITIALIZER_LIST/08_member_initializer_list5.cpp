#include <iostream>

class Point
{
	int x;
	int y;
public:
//	Point() 			: x{0}, y{0}{} 
	Point(int a, int b) : x{a}, y{b}{} 
};

// 핵심 : Point 의 디폴트 생성자가 없습니다
//		 아래 코드가 왜 에러인지 정확히 알아야 합니다.

class Rect
{
	Point leftTop;
	Point rightBottom;
public:
	// 아래 생성자는 컴파일러가 만드는 아래 코드(주석)때문에 에러
	/*
	Rect()
	{
		// call Point::Point()
		// call Point::Point()
	}
	*/
	Rect() : leftTop(0, 0), rightBottom{0, 0}  // 동일방법이 좋은데 
	{										// 다양한 방법을 보여주기 위해 수업용
		// call Point::Point(0, 0)
		// call Point::Point(0, 0)
	}
	

};

int main()
{
	Rect rc; 
}
