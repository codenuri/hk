#include <iostream>

// 생성자에서 멤버 데이타에 값을 넣는 방법

class Point
{
	int x, y;
public:
	/*
	// #1. {} 안에서 대입
	Point(int a, int b) 		
	{
		x = a; 	// bad
		y = b;
	}
	*/
	
	// #2. member initializer list 사용.
	Point(int a, int b) : x(a), y(b) 	// good
	{
	}

};



int main()
{
	Point pt(0, 0);
}




