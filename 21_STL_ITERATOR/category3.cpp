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

	// std::find 는 1, 2인자로 반복자를 요구 합니다.
	// => 최소 요구조건을 5가지중에 무엇일까요 ?
	// => 입력 반복자
	auto ret1 = std::find(s1.begin(), s1.end(), 3);	

	std::reverse(s1.begin(), s1.end()); // bidirectional iterator 요구구

	std::reverse(s2.begin(), s2.end()); // error
						// std::reverse가 양방향 반복자를 요구하는데
						// 싱글리스트 반복자는 양방향 반복자 가 아니다.

//	std::sort(s1.begin(), s1.end()); // 퀵소트 알고리즘입니다.
									 // 요구 조건은 ? 임의 접근 반복자
									// => s1 은 list 반복자
									// 양방향 반복자.  error
	s1.sort(); // list 는 std::sort()(퀵) 으로 보낼수 없으므로
			   // 멤버함수 sort 제공(퀵 아님)

	std::vector<int> v = {1,3,2,4};
	v.sort(); // 이 멤버 함수가 있다 ? 없다 ?
}

// cppreference.com 에서 std::find 검색해서 선택하세요
// std::find 문서에서 함수 모양 보세요

template<class InputIter, class T>
InputIter find( InputIter first, InputIter last, T value)
/*
std::sort() 찾아서 인자 보세요 
RandomIter
*/
void 함수()

int main()
{
	함수(foo);
	함수(&foo);

}