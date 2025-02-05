#include <iostream>

// noexcept 키워드의 2가지 용도
// 1. 함수가 예외가 있는지 조사
// 2. 함수가 예외가 없음을 컴파일러에게 알릴때 사용

// 참고 : C/C++ 컴파일러(링커가 아닌)는
// => 컴파일시 함수의 구현 자체가 없어도
// => 선언만 있으면 컴파일 가능합니다.
// => 따라서, 예외가능성 여부의 조사를 하는 것은
//    함수 개발자가 함수 만들때 함수 선언에 표기해주어야 하고, 그것을 조사하는 것

// 모든 함수는 예외가 있다
// 그런데, 함수가 예외가 없음을 보장할수 있다면 noexcept 붙여라.
// => 즉, 예외가 없다는 것은 함수 개발자가 알려주는것

void foo() 
{
}
void goo() noexcept
{
	
}

int main()
{
	// noexcept(함수호출표현식) : 함수호출시 예외가 없는가를 조사하는 것
	bool b1 = noexcept(foo());
	bool b2 = noexcept(goo());

	std::cout << b1 << std::endl; 
	std::cout << b2 << std::endl;
}

// 함수 안에서 예외 없을때만 noexcept 붙여야 합니다

// f1 예외 있음. noexcept 붙이면 안됨
void f1()
{
	int* p1 = new int; // 메모리 부족시 "std::bad_alloc 발생"

	delete p;
}

// 아래 함수는 내부적으로 발생하는 모든 예외를 외부에 다시 던지지 않습니다.
// => noexept 붙여도 됩니다.
void f2() noexcept
{
	try
	{
		int* p1 = new int; // 메모리 부족시 "std::bad_alloc 발생"
		delete p;
	}
	catch(...)
	{
	}
}
// 아래 함수 예외 없습니다.
int add(int a, int b) noexcept 
{
	return a + b;
}
// 함수가 예외 가능성이 없을때만 noexcept 붙이세요
// => 잘 모르면 붙이지 마세요

// 왜 붙이나요 ?
// => 기계어 코드가 보다 최적화 됩니다.
// => move 개념배울때 반드시 noexcept 붙여야 하는 이유 나옵니다.(내일)




