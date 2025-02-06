// godbolt.org 띄우세요
// 아래 선택된 만큼만 넣으세요요
#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>

int main()
{
	std::vector<int> v = { 1,3,5,7,9,2,4,6,8,10 };


	std::sort(v.begin(), v.end(), [](int a, int b) { return a < b;} );	

	// 람다 표현식의 정확한 원리.
	// => 결국 람다 표현식은 컴파일러에게 "함수객체클래스"를 만들어 달라는 표기법
	// => 함수객체를 간단하게 만들수 있는 기술입니다
	// => 위 한줄을 컴파일러가 아래 코드로 변경합니다.
	
	class CompilerGeneratedName
	{
	public:
		inline auto operator()(int a, int b) const 
		{
			 return a < b;
		}
	};

	std::sort(v.begin(), v.end(), CompilerGeneratedName{} );	

}





