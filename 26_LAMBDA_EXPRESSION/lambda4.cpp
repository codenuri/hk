#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	std::vector<int> v = { 1,2,6,5,4,3,7,8 };

	// 주어진 구간에서 "3의 배수"를 찾고 싶다. 

	auto p1 = std::find_if(v.begin(), v.end(), [](int n){ return n % 3 == 0;}  );


	int k = 3;

	// 주어진 구간에서 "k의 배수"를 찾고 싶다. 
	// => 일반 함수로는 할수 없었습니다.
	// => 함수 객체로는 할수 있었습니다
	// => 람다 표현식도 당연히 할수 있습니다
	
	// 람다 표현식에서 outer 함수(main함수)의 지역변수를 사용하는 것을
	// => 캡쳐(capture) 한다 라고 표현합니다
	auto p2 = std::find_if(v.begin(), v.end(), [k](int n){ return n % k == 0;}  );

	// 캡쳐의 원리
	// => 아래 클래스를 만듭니다

	class CompilerGeneratedName
	{
		// 지역변수 캡쳐 문법을 사용하면 컴파일러가 만드는 클래스에 멤버 데이타가 추가됩니다.
		int k; 
	public:
		CompilerGeneratedName(int n) : k(n) {}

		inline auto operator()(int n) const 
		{
			return n % k == 0;
		}
	};
	auto p3 = std::find_if(v.begin(), v.end(), CompilerGeneratedName{k}  );

}



