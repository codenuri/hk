#include <iostream>

// 인자의 원본데이타를 1증가하고 싶다.
void inc1(int n)  { ++n; }
void inc2(int* p) { ++(*p); }
void inc3(int& r) { ++r; } 

int main()
{
	int a = 1, b = 1, c = 1;

	inc1( a ); // call by value	
	inc2( &b); // call by pointer
	inc3( c ); // call by reference

	std::cout << a << std::endl;	// 1
	std::cout << b << std::endl;	// 2
	std::cout << c << std::endl;	// 2
}

// 레퍼런스를 함수 인자로 사용하면
// 포인터 처럼 원본 데이타를 수정할수 있습니다.
// => 레퍼런스 권장
// 장점 1. 가독성(간결하다)
// 장점 2. safety(안전하다.)