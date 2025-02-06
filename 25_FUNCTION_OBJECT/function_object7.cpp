#include <iostream>
#include <algorithm>

inline bool cmp1(int a, int b) { return a < b; }
inline bool cmp2(int a, int b) { return a > b; }
struct Less   { inline bool operator()(int a, int b) { return a < b; }};
struct Greater{	inline bool operator()(int a, int b) { return a > b; }};

int main()
{
	int x[10] = { 1,3,5,7,9,2,4,6,8,10 };

	// C++ 표준 sort()는 템플릿 입니다.
	// => 사용자가 전달한 인자를 가지고 "함수를 생성" 한다는 의미.


	// 1. 비교 정책으로 일반함수 사용시

	// 장점 : 비교정책을 다른 함수로 여러번 교체해도 생성된 sort()함수는 한개이다.
	//		 => 코드 메모리 증가안함.

	// 단점 : 비교 정책 함수가 sort() 내부에 인라인 치환될수 없습니다.
	//		 수백 ~ 수천번의 비교함수를 호출해야 합니다.
	//	     데이타 양이 많은 성능이슈!!

	std::sort(x, x+10, cmp1); // sort(int*, int*, bool(*)(int, int) ) 인 함수를 생성해서 사용
	std::sort(x, x+10, cmp2); // sort(int*, int*, bool(*)(int, int) ) 인 함수생성


	// 2. 비교정책으로 함수객체 사용시

	// 단점 : 비교 정책을 교체한 횟수 만큼의 sort() 함수 생성
	//		 => 즉, 정책당 별도의 sort() 함수

	// 장점 : sort() 함수 안에 비교정책이 인라인 치환되어 있다.
	// 		=> 빠르다.!

	Less    f1;
	Greater f2;
	std::sort(x, x+10, f1); // sort(int*, int*, Less)    인 함수를 생성해서 사용
	std::sort(x, x+10, f2); // sort(int*, int*, Greater) 인 함수를 생성해서 사용
}









