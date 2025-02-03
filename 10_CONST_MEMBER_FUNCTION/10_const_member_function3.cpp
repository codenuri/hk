#include <iostream>

//void foo(int* p) {}
//void foo(const int* p) {}


// 동일이름의 상수/비상수 함수를 동시에 제공가능합니다.
class Test
{
public:
	// void foo(Test* this) {}
	// void foo(const Test* this) {}
	void foo()       { std::cout << "foo" << std::endl; }			// 1
	void foo() const { std::cout << "foo const" << std::endl; }		// 2
};

int main()
{
	const Test ct;	// 상수 객체는
	ct.foo();		// 상수 멤버함수만 호출 가능 - 2번 호출출

	Test t; 	// 상수가 아닌 객체는
	t.foo();	// 1. non-const(1번) 멤버 함수 호출
				// 2. 1이 없다면 2번 호출출
}

// 결국 동일 이름함수의 상수/비상수 멤버 함수를 제공하는 것은
// 상수객체와 비상수 객체일때 다르게 동작하고 싶을때
