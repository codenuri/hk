// 6_알고리즘1
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

int main()
{
	std::list<int>   s = { 1,2,3,4,5,6,7,8,9,10 };
	std::vector<int> v = { 1,2,3,4,5,6,7,8,9,10 };

	// 컨테이너에서 3을 찾고 싶다.

	// 방법 1. 멤버함수 find를 제공하자.
	// 장점 : 사용자 입장에서는 사용하기 쉽다.
	// 단점 : 모든 컨테이너에 find 멤버 함수 만들어야 한다. - C++ 표준만들때 이점이 싫었다
	s.find(3);
	v.find(3); 

	// 방법 2. find 를 멤버가 아닌 일반 함수(템플릿)으로 제공하자.
	// => 장점 : 한개의 find 함수(템플릿) 으로 모든 컨테이너에서 선형검색 가능
	// => 단점 : 사용하는 코드가 복잡해 보인다.
	auto ret1 = std::find(s.begin(), s.end(), 3);
	auto ret2 = std::find(v.begin(), v.end(), 3);

//	auto ret3 = std::find(v, 3); // 이렇게 할수는 없었을까 ??
								 // C++98 시절 기술적인 문제로 만들수 없었다.
								 // C++20 부터 해결. 
	auto ret3 = std::ranges::find(v, 3); // ok. C++20 부터 -std=c++20 옵션필요요							 
}
