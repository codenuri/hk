#include <iostream>
#include <vector>

// vector4.cpp
class Point
{
	int x, y;
public:
	Point( int a, int b) : x(a), y(b) 
	{
		std::cout << "Point()\n";
	}
};
int main()
{
	// 힙에 Point 객체 한개 만들기 - ok
//	Point* p1 = new Point(0,0);

	// 힙에 Pont 객체 10개 만들어보세요(연속적인 메모리 사용하게 하세요)
//	Point* p2 = new Point[10];	// 디폴트 생성자를 10번 호출해야 한다.
								// 그런데, Point 는 디폴트 생성자가 없다.
								// error. 

	// 메모리 할당과 생성자 호출을 분리하면 유연성이 좋아집니다.
	Point* p2 = static_cast<Point*>( operator new( sizeof(Point)*10));

	// 할당된 10개 크기의 메모리에, 10개의 객체를 생성합니다.
	for(int i = 0; i < 10; i++)
	{
	//	new(&p2[i]) Point(0, 0);
		new(p2+i) Point(0, 0);
	}

	// 소멸자 호출
	for(int i = 0; i < 10; i++)
	{
		p2[i].~Point();
	}

	operator delete(p2);


	//---------------------------------
	int* p = new int[10]; // 실제 몇바이트 할당할까요 ?
	delete p;

//	delete[] p;
}
/*
operator new() 함수 이름
new : 키워드
*/

/*

double d; // 8 byte
char* p =(char&)&d;
*/