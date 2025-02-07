#include <iostream>
#include <functional>

void f1(int a) {}
void f2(int a, int b) {}

void foo(int a, int b, int c, int d)
{
	printf("foo : %d, %d, %d, %d\n", a, b, c, d);
}

struct Dialog 
{	
	void close(int code) {} 
};

int main()
{
	// C 언어의 함수 포인터 문제점
	// => signature(인자 갯수와 타입) 이 같은 함수의 주소만 보관할수 있습니다.
	/*
	void(*f)(int); 
	f = &f1;	// ok
	f = &f2;	// error.
	*/

	// std::function<> 은 함수 포인터의 역활을 하는 C++표준라이브러리(C++11)
	// 사용법 : std::function<함수모양(타입)>

	std::function<void(int)> f;

	f = &f1;
	f(10); // f1(10). 즉, 기본 사용법은 함수 포인터 와 동일

//	f = &f2;	// error. f2는 인자가 2개

	// std::function 의 장점 : std::bind 의 반환값 저장 가능
	f = std::bind(&f2, 3, _1);
	f(10); // f2(3, 10)

	f = std::bind(&foo, 3, _1, 7, 9 ); 
	f(10); // foo(3, 10, 7, 9)

	// 결국 std::bind 덕분에 인자가 int 한개 "이상" 있는 모든 함수는
	// f에 담을수있습니다.

	// 멤버 함수를 bind 할때는 객체 주소만 같이 전달하면 됩니다.
	Dialog dlg;
	f = std::bind(&Dialog::close, &dlg, _1);
	f(10);
}