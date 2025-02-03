#include <iostream>

struct Rect
{
	int left;
	int top;
	int right;
	int bottom;

	int get_area() { return (right - left) * (bottom - top); }
	void draw() { std::cout << "draw rect" << std::endl; }
};
int main()
{	
	// #1. Rect 형 변수를 만들면
	// => 멤버 데이타만 각각 메모리에 놓이게 되고
	// => 멤버 함수는 변수의 갯수에 상관없이 코드메모리에 한개만있다.

	Rect r1 = { 1,1,10,10 }; 
	Rect r2 = { 1,1,10,10 };

	std::cout << sizeof(r1) << std::endl; // 16


	// #2. 용어
	int n1 = 10; 	// n1 은 "변 하는 수" 라서 변수 입니다.
	n1 = 20;		// 

	Rect r = { 1, 1, 10, 10 };	// r은 변하는 수가 아닌
								// 사각형 한개를 나타냅니다.
								// 객체 라고 합니다.

	// 객체 : 세상에 존재하는 모든 것
	//		 int n 에서 n 도 사실 객체 입니다.

	// 관례상
	// primitive 타입을 메모리에 생성한것   : 변수
	// user define 타입을 메모리에 생성한것 : 객체
}
