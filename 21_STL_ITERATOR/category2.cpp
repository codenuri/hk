#include <iostream>
#include <algorithm> 
#include <list>			// 더블리스트 
#include <forward_list> // 싱글리스트
#include <vector>

// iterator 의 5가지 분류(category)

// 입력(input)    		: ++p, =*p
// 출력(output)   		: ++p, *p= 
//----위 2개 멀티패스 보장안함, 아래 3개 멀티 패스보장 ------
// 전진(forward)  		: ++p, =*p		   	  싱글리스트
// 양방향(bidirectional): ++p, =*p, --p,      더블리스트
// 임의 접근(random)    : ++p, =*p, --p, +, -, []   연속된메모리(vector)












int main()
{
	std::list<int>         s1 = {1,3,5,7,9,2,4,6,8,10};
	std::forward_list<int> s2 = {1,3,5,7,9,2,4,6,8,10};

	auto p1 = s1.begin(); // 더블리스트 반복자
	auto p2 = s2.begin(); // 싱글리스트 반복자

	// 다음중 에러를 예측해 보세요. 이유도 생각해 보세요
	++p1;	// 1 ok
	--p1;	// 2 ok

	++p2;	// 3 ok
	--p2;	// 4 error. 자료구조 특성상 앞쪽요소의 주소를 알수 없다.
}

