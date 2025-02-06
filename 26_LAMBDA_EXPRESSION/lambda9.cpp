#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

// C 로부터 C++처음 만들었을때 이름 "C front"!!

// 지금까지의 C++을 버리고 완전히 새로 만들자는 주장이 있습니다 => "C++ front"!

// => 오래된 모든 기술 버리고 새로운 좋은것만 으로.
// => 전직 "C++표준위원회 위원장" 이 주도 - herb shutter

// 유튜브 "cppcon" 채널 검색 후 "herb shutter" 이나 "C++front" 검색색

int add(int a, int b) { return  a + b;}

// 람다를 많이 사용하는 개발자분들은 아래와 같이 모든것을 람다로 하는 경우도 
// 꽤 많습니다.
auto add = [](int a, int b) { return a + b;};

int main()
{
	// 람다표현식과 반환 타입
	// => 표기하지 않으면 auto 로 반환 
	// => 추론 불가능할때만 표기하세요

	auto f1 = [](int a, double b) { return a + b;};

	auto f2 = [](int a, double b) { if( a == 0) return b; return a + b;};

//	auto f3 = [](int a, double b) { if( b == 0) return a; return a + b;};
										// => error
										// => 2개의 return 문장이 다른 타입반환

	// 해결책 : 후위 반환 타입 문법으로 반환 타입을 표기하면 됩니다.
	auto f4 = [](int a, double b) -> double { if( b == 0) return a; return a + b;};										
}


