#include <iostream>

int main()
{
	int v1 = 10, v2 = 10;

	// #1. 아래 코드에서 "v1 = 20" 은 복사본의 변경입니다.
	auto f1 = [v1, v2](int a) mutable { v1 = 20; return a + v1 + v2; }; // ok

	// #2. "참조캡쳐" 를 하면 원본을 변경할수 있습니다.
	auto f2 = [&v1, &v2](int a)  { v1 = 20; return a + v1 + v2; }; // ok

	f2(0); 	// "v1 = 20" 의 코드가 main 함수의 원본 v1 을 변경

	std::cout << v1 << std::endl;  // 20



	//--------------------------
	class CompilerGeneratedName 
	{
		int& v1;
		int& v2;
	public:
		CompilerGeneratedName(int& a, int& b) : v1(a), v2(b) {}

		inline auto operator()(int a) const 
		{
			v1 = 20;		// v1 은 참조 입니다.(참조는 결국 포인터 개념)
							// 이 코드는 v1자체가 아닌
							// v1의 대상체를 변경하는 코드 입니다.
							// 포인터 개념으로 생각하세요
							// *(v1이관리하는주소) = 20

			return a + v1 + v2;
		}
	};
	auto f3 = CompilerGeneratedName{v1, v2}; 

	// 결론 : 람다 사용시 캡쳐 방법
	// #1. capture by value
	auto f4 = [v1, v2](int a)         { v1 = 20;}; // error. 읽기만 가능
	auto f5 = [v1, v2](int a) mutable { v1 = 20;}; // ok. 쓰기 가능.
												   // 단, 복사본 변경한것
	// #2. capture by reference
	// => 복사본 생성 안함
	auto f6 = [&v1, &v2](int a) { v1 = 20;}; // ok. 원본 수정
}





