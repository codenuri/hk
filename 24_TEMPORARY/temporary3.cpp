#include <iostream>

class Point
{
	int x, y;
public:
	Point(int x, int y) : x{x}, y{y} { }
	~Point()                         { }
};

//======================================================
void draw_line(const Point& from, const Point& to) {}

int main()
{
	// (10, 10) ~ (20, 20) 에 선을 그리고 싶다.

	// #1. named object 를 사용하면
	Point from(10, 10);
	Point to(20, 20);

	draw_line(from, to);	

	// 함수 호출뒤 더이상 from, to 는 필요 없지만
	// {}을 벗어날때 까지는 메모리에 존재

	// #2. temporary(unamed object) 를 함수 인자로 사용
	draw_line( Point(10, 10), Point(20,20) );	// 함수 호출뒤에는
											// 즉시, 임시객체 파괴

	// 참고 : 임시객체 만들때 () 사용하면 "함수호출" 처럼 보여서 헷갈릴수 있습니다.
	//       그래서 요즘은 {} 권장
	
	draw_line( Point{10, 10}, Point{20,20} );

}
/*
void foo()
{
	sub esp, 400
	int n;
	{
		int a = 0;

	}// <= a 파괴

	add esp, 400
} // <= n 파괴
*/