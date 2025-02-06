#include <iostream>
#include <vector>
#include <algorithm>

// 람다표현식과 타입

int main()
{
	// #1. 모든 람다 표현식은 다른 타입 입니다.
	auto f1 = [](int a, int b) { return a + b; };
				// class xxx{ operator()() }; xxx{};

	auto f2 = [](int a, int b) { return a + b; };
				// class yyy{ operator()() }; yyy{};


	// 즉, f1 과 f2 는 다른 클래스로 만든 객체 입니다.
	// => 아래 처럼하면 클래스 이름확인 가능합니다.
	// => 아래 결과를 c++filt -t "결과로나온이름" 하면 보다 정확히 알수있습니다.
	std::cout << typeid(f1).name() << std::endl;
	std::cout << typeid(f2).name() << std::endl;
	//-------------------------------------------------


	auto f3 = [](int a, int b) { return a + b; };

	// 람다표현식으로 이미 초기화된 변수에, 다른 람다 표현식 담을수 없습니다.
	// => 타입이 다릅니다.
	// => 즉, 한번 람다표현식으로 초기화된 변수를 절대 변경할수 없습니다.
	f3 = [](int a, int b) { return a + b; }; // error

	// 위 사실 아주 중요합니다.
	// => 이유는 다음소스 주석 보세요.. (생각해 보세요.)
}
