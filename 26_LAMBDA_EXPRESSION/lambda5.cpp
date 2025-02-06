#include <iostream>

int main()
{
	int v1 = 10, v2 = 10;

	// #1. 람다표현식에서 outer 함수(main함수) 지역변수 사용하려면 
	//    캡쳐해야 합니다
	// => [v1, v2] 
	auto f1 = [v1, v2](int a) { return a + v1 + v2; }; 


	// #2. "값에 의한 캡쳐"는 지역변수 "변경" 은 안됩니다.
//	auto f2 = [v1, v2](int a) { v1 = 10; return a + v1 + v2; };  // error

	// #3. mutable lambda 는 지역변수 변경됩니다.
	// => operator()() 함수를 const-const member function 으로 해달라!
	auto f3 = [v1, v2](int a) mutable { v1 = 20; return a + v1 + v2; }; // ok

	f3(0); // 이순간 v1 = 20 실행되었습니다.

	std::cout << v1 << std::endl; // 10

	std::cout << sizeof(f3) << std::endl; // 8


	//--------------------------
	class CompilerGeneratedName 
	{
		int v1;
		int v2;
	public:
		CompilerGeneratedName(int a, int b) : v1(a), v2(b) {}

//		inline auto operator()(int a) const 
		inline auto operator()(int a) 		// mutable 람다로 만들면 이렇게게
		{
			v1 = 20;	// error. 상수 멤버함수안에서 값 변경 안됨.
						// mutable 람다라면 에러 아님.
			return a + v1 + v2;
		}
	};
	auto f3 = CompilerGeneratedName{v1, v2}; // 여기서 v1, v2 는
											 // main 의 지역변수
}





