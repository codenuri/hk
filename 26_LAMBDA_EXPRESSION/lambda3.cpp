#include <iostream>
#include <algorithm>
#include <vector>

int main()
{
	std::vector<int> v = {1,3,5,2,4,6};

	// 람다 표현식 활용 1. STL 알고리즘의 인자로 사용
	std::sort(v.begin(), v.end(), [](int a, int b) { return a < b; });

	
	// 람다 표현식 활용 2. auto 변수에 담아서 함수 처럼 사용

	auto f = [](int a, int b) { return a + b;};
		// class xxxx{ operator(){} }; xxx{}; 
		// 즉, 람다표현식의 최종 결과는 임시객체(결국 최종결과가 객체라는 것)
		// Point p1;
		// Point p2 = p1; // 어떤 객체는 자신과 동일타입 객체에 복사할수 있다


	// 이제 f 는 함수 처럼 사용하면 됩니다.
	// => 의미. main 함수 안에서 만든 함수(객체)
	// => C++은 함수 안에서 함수를 만들수 없습니다.
	// => 그런데, 람다 표현식으로는 가능합니다
	int n = f(1, 2);

}

	