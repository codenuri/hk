// 67page
#include <iostream>

// OOP 개념 1. 필요한 데이타 타입을 먼저 설계 하자.
// OOP 개념 2. 타입을 만들때 상태를 나타내는 데이타와
//			  상태를 가지고 연산을 수행하는 함수를 묶자

// C 구조체   : 함수를 포함할수 없다.
// C++ 구조체 : 함수를 포함가능

// 함수를 포함해서 얻는 장점이 뭡니까 ?
// 1. 인자로 데이타를 전달할 필요 없다.
// 2. 다양한 객체지향 문법으로 데이타를 안전하게 보호 가능. - 앞으로 배우는 내용. 

struct Rect
{
	int left;
	int top;
	int right;
	int bottom;

	int get_area()
	{
		return (right - left) * (bottom - top);
	}
	void draw()
	{
		std::cout << "draw rect" << std::endl;
	}	
};

int main()
{
	Rect rc = {1,1, 10, 10};

//	int n1 = get_rect_area(rc);	// C 스타일
//	draw_rect(rc);

	int n1 = rc.get_area(); // C++ 스타일
	rc.draw();
}