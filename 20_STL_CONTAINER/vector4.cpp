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
	/*
	Point* p1 = new Point(0,0);	// 1. 힙에 sizeof(Point) 만큼의 메모리 할당
								// 2. 생성자 호출
	delete p1;	// 1. 소멸자 호출
				// 2. 메모리 해지
	*/

	// 1. 메모리만 할당해 달라. void* operator new() 이므로 캐스팅 필요
	Point* p2 = static_cast<Point*>( operator new(sizeof(Point))); 

	// 2. 할당된 메모리에 생성자만 호출
//	new(p2) Point(0, 0); // C++98 ~ . placement new 기술
	std::construct_at(p2, 0, 0); // C++20 ~

	// 3. 메모리 해지 없이 소멸자만 호출
//	p2->~Point(); // C++98 ~
	std::destroy_at(p2); // C++17 부터 지원. 위와 동일

	// 4. 메모리만 제거
	operator delete(p2);
}

// malloc : 메모리 할당
// new    : 객체의 생성 ( 메모리 할당 + 생성자 호출)

// new Point      : 새로운 메모리에 객체를 생성해 달라
// new(주소) Point : 주소위치에 객체를 생성해 달라 

// 리눅스
// Point* p = mmap(sizeof(Point)); // 프로세스간 공유를 위한 공유메모리 할당
// new (p) Point(0,0);

