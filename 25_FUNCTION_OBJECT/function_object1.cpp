#include <iostream>

// 237 page ~ 

// #1. 함수 객체(function object)
// => () 연산자를 재정의 해서 함수 처럼 사용가능한 객체

// 왜??? 그냥 함수로 하면 되는데 함수객체를 사용하나요 ?
// 1. 상태를 가지는 함수 만들기!!
// 2. 특정 상황에서 함수 보다 함수객체가 빠릅니다.
// 3. C++20 부터 추가된 새로운 C++ 표준 라이브러리는 
//    함수가 아닙니다. 함수 객체입니다.


struct Plus
{
	int operator()(int a, int b)
	{
		return a + b;
	}
};
int main()
{
	Plus p;		// p 는 함수가 아닌 객체 입니다.(Plus 타입)

	int n1 = p(1, 2); // 객체인 p를 함수 처럼 사용합니다. 함수객체 라고 합니다.
					  // 이 코드는 
	int n2 = p.operator()(1, 2); // 이렇게 해석 됩니다.

	// 아래 주석을 먼저 정확히 이해 하세요
	// a + b => a.operator+()
	// a - b => a.operator-()
	// a()   => a.operator()()
	// a(1, 2) => a.operator()(1, 2)
}


