#include <iostream>
#include <algorithm>
#include <functional> // std::less<>, std::greater<> 가 이미 있습니다.(C++98)
#include <vector>

// 248 page ~ 

bool cmp(int a, int b) { return a < b; }

int main()
{
	std::vector<int> v = { 1,3,5,7,9,2,4,6,8,10 };
	
	// sort 하고 싶다면
	
	// #1. 비교 함수를 전달하지 않은 경우 - 오름차순으로 정렬
	std::sort( v.begin(), v.end() );  // 1,2,3,4,5,6,7,8,9,10

	// #2. sort 방식을 변경하고 싶다면(내림차순, 절대값비교등....)
	// => 3번째 인자로 비교 정책 전달
	// => 비교정책은 "binary predicator 이어야 합니다.
	
	// #2-1. 비교정책으로 일반함수 전달
	// => 비교정책이 인라인 치환 안됨.
	std::sort(v.begin(), v.end(), cmp);	


	// #2-2. 비교정책으로 함수 객체 전달
	// => 인라인 치환되어서 빠릅니다.

	std::less<int> f1;  // <functional> 헤더에 C++98 시절부터 지원

	std::sort(v.begin(), v.end(), f1);	

	// less 객체를 한번만 사용한다면 임시객체로 전달을 권장
	std::sort(v.begin(), v.end(), std::less<int>{} );	
	std::sort(v.begin(), v.end(), std::greater<int>{} );

	// #2-3. C++11 부터는 비교정책으로 람다 표현식 권장
	// => 비교정책을 담은 람다표현식은 sort 안에서 인라인 치환 !
	// => 결국, 가장 권장하는 방식.
	// => 단, 코드메모리 증가 가능성 있음. 
	std::sort(v.begin(), v.end(), [](int a, int b) { return a < b;} );	

}





