// COPY_MOVE 폴더에 temp1.cpp 만드세요
// => 어제 소스중 temporary3.cpp 복사해 오세요(git에 있습니다.)

#include <iostream>

class Point
{
	int x, y;
public:
	Point(int x, int y) : x{x}, y{y} { }
	~Point()                         { }
};

// 함수 인자로
// const Point& 의도 : 인자로 전달된 객체를 읽기만 하겠다
//       Point& 의도 : 인자로 전달된 객체를 읽기/쓰기 모두 하겠다

void draw_line(const Point& from, const Point& to) {}

void init( Point& pt) { pt.x = 10; }  // <== 추가

int main()
{
	draw_line( Point{10, 10}, Point{20,20} );

	init( Point{0, 0} ); // <== 생각해 보세요
						 // error.
						 
}

// C++ 창시자가 왜 이문법을 만들었는가 설명하는 책
// => ARM : Annoted Reference Manual 



