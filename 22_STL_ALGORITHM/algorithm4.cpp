// 6_알고리즘1
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

bool foo(int n) { return n % 3 == 0; }
void foo() {}

int main()
{
	std::vector<int> v = { 1,2,9,4,3,6,7,3,9,10 };

	// 조건자로 "일반함수 사용하는 코드"
//	auto ret1 = std::find_if(v.begin(), v.end(), foo ); 
	auto ret1 = std::find_if(v.begin(), v.end(), static_cast<bool(*)(int)>(foo) ); 

	// 조건자로 "람다 표현식" 사용하는 코드
	// => 함수의 이름(또는 주소)가 필요한 위치에 함수 구현을 직접 표기하는 문법
	// => "익명의 함수" 라고도 합니다.
	// [] : lambda introducer. 람다표현식이 시작됨을 알리는 기호

	auto ret2 = std::find_if(v.begin(), v.end(), 
							 [](int n) { return n % 3 == 0; }  ); 

}




