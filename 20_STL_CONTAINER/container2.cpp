#include <iostream>
#include <vector>
#include <list>
#include <deque>

// 컨테이너(Container ) : 여러개의 요소를 보관하는 클래스
//						list, vector, deque 등
//						다른 언어에서는 collection 이라고도 합니다.

int main()
{
	std::vector<int> v = { 1,2,3,4,5 };
	std::list<int>   s = { 1,2,3,4,5 };

	// #1. 제거와 반환을 동시에 하는 멤버 함수는 없습니다.
	// => 안전한 컨테이너를 만들기 위해서 선택한 방법.
	// => 예외 안전성의 "강력보장" 을 지키기 위한 어쩔수 없는 디자인
	int n = v.back();	// 마지막 요소(5)를 반환만, 제거되는 것은 아님.
	v.pop_back();		// 제거만 하고, 반환은 안함. 리턴 타입 void

	std::cout << n << std::endl;


	// 2. 컨테이너가 컨테이너를 보관하면 편리한 "자료구조"를 만들수 있습니다.

	std::vector< int > v1(10);
	std::vector< std::list<int> > v2(10);

	v1[0] = 10;

	v2[0].push_back(10);
	v2[0].push_back(20);
	v2[1].push_back(1);
	v2[1].push_back(2);

	// 3. 멤버 타입 개념
	// => ? 위치에 auto 말고, 최선의 코드는 ?
	// => cppreference.com 에서 std::vector 찾으세요
	// => 도움말에서 "member function" 항목 위를 보세요
	//              "member type" 찾으세요

//	unsigned int sz = v1.size();
	std::vector<int>::size_type sz = v1.size(); // 100점!!!
	auto sz = v.size();
}

template<typename T>
class vector 
{
public:
	// vector 의 멤버 함수 구현에서 사용할 타입을 미리 정의 합니다
	using size_type = unsigned int; // typedef unsigned int size_type;

	// 이제 멤버 함수 만들때 size_type 을 사용합니다.
	size_type size() const { return 10;}
};

