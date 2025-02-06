#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

int main()
{
	std::vector<int> v = {1,3,5,7,9,2,4,6,8,10};

	// 아래 코드를 평가해 보세요
	// => 아래 코드는 같은 람다표현식을 3번 사용했지만, 모두 다른 타입입니다.
	// => 그래서 std::sort() 함수가 실제로 3개 생성됩니다.
	// => 코드 메모리 증가.
	std::sort(v.begin(), v.end(), [](int a, int b) { return a < b; });
	std::sort(v.begin(), v.end(), [](int a, int b) { return a < b; });
	std::sort(v.begin(), v.end(), [](int a, int b) { return a < b; });

	// 동일한 람다표현식을 여러번 사용하게 된다면
	// => auto 변수에 담아서 사용하세요
	auto cmp = [](int a, int b) { return a < b; };
				// class xxx{}; xxx{};

	// 아래 코드는 결국 cmp 가 항상 같은 타입이므로 한개의 std::sort()함수수 만 생성됩니다.
	std::sort(v.begin(), v.end(), cmp);
	std::sort(v.begin(), v.end(), cmp);
	std::sort(v.begin(), v.end(), cmp);

	//----------------------------
	// 그런데, 2개의 요소를 < 비교하는 함수객체는 C++98 시절부터 이미 있다.
	std::less<int> f;
	
	std::sort(v.begin(), v.end(), f);
	std::sort(v.begin(), v.end(), f);
	std::sort(v.begin(), v.end(), f);

	// 그래서 람다표현식을 권장하지만!!
	// => < > 등 기본 비교는 
	// => 예전부터 있던 std::less, std::greater 를 사용하는게 좋다!

}
