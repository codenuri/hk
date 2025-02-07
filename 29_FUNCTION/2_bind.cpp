#include <iostream>
#include <functional> // 이헤더에 std::bind
using namespace std::placeholders; // 이 안에 _1, _2, _3 .. 이 있습니다.


// C++ 함수 포인터를 대신하기 위해 만든 도구 : std::bind & std::function

// std::bind : N 항 함수(객체) 를 일부 인자를 고정해서 M 항 함수로 만드는 도구
//			   (단, N >= M )

void foo(int a, int b, int c, int d)
{
	printf("foo : %d, %d, %d, %d\n", a, b, c, d);
}

int main()
{
	foo(10, 20, 30, 40);	// foo 는 4항함수수

	// std::bind : 기존 함수의 인자를 고정한 새로운 함수 만들때 사용

	// auto f = std::bind(N항 함수, N개인자); 

	auto f0 = std::bind(&foo, 10, 20, 30, 40); // 4항함수 =>0 함수로 변경경
	f0();	// foo(10, 20, 30, 40)


	auto f2 = std::bind(&foo, 10, _1, 30, _2); // 4항 함수 => 2항 함수로
	f2(5, 9); // foo(10, 5, 30, 9)


	auto f3 = std::bind(&foo, 7, _2, _1, 2 );

	f3(9, 3); // "foo : 7, 3, 9, 2" 나오게 만들어 보세요	

	// std::bind
	// => 기존함수의 인자를 고정하거나, 순서를 변경하는 
	// => 새로운 함수를 만드는 도구

	// std::bind 의 반환값
	// => 인자를 어떻게 전달하는가에 따라 타입이 다릅니다(템플릿)
	// => 그래서, auto 또는 std::function 에만 담을수 있습니다.
}