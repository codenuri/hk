// 5_반복자1
#include <iostream>
#include <vector>
#include <list>

int main()
{
//	std::list<int>   s = { 1,2,3,4,5,6,7,8,9,10 };
	std::vector<int> s = { 1,2,3,4,5,6,7,8,9,10 };


	// 1. 반복자의 정확한 타입
	// => "컨테이너이름::iterator"
	// => 그런데, 절대 아래처럼하지 마세요
	// => 컨테이너 변경시 아래 코드 수정됩니다.
//	std::list<int>::iterator p1 = s.begin(); 

	// 아래 처럼 사용하면 컨테이너 변경시 코드 수정안됩니다.
	auto p1 = s.begin(); 
		
}








namespace std
{
	// 아래 코드가 실제 반복자 클래스.. 이름은 컴파일러 제조사 마다 다름.. 
	template<typename T>
	class slist_iteratorxxxxx 
	{
		Node* current;
	public:	
		slist_iteratorxxxxx(Node* n) : current(n) {}

		slist_iteratorxxxxx& operator++() 
		{
			current = current->next;
			return *this;
		}
	};

	template<typename T>
	class list
	{
	public:
		using size_type = unsigned int;
		using iterator = slist_iteratorxxxxx<T>;
	};
}
// using 의 3가지 용도. 
using dword = int; // using alias 문법 => 별명 만들기

using namespace std; // using directive => namespace 안의 모든 요소를 namespace 이름없이

using std::swap;    // using declaration  => swap 만 std:: 이름 없이, 


