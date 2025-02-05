// init1.cpp
#include <initializer_list>

void foo(std::initializer_list<int> e)
{
}
int main()
{	
	// 우변의 데이타가 배열과 동일하게 메모리에 놓이고
	// e 는 아래 2중한개로 구현
	// 1. 시작주소와 갯수
	// 2. 시작과 마지막 주소
	// vector 는 데이타가 힙
	// initializer_list<int>는 stack
	// 배열과 차이점은 "함수 인자로 보내기 위해 설계 한것"
	std::initializer_list<int> e = {1,2,3,4,5};

	// e 사용법은 STL 반복자처럼
	auto first = e.begin();
	//---------------------
	// 함수 인자가 initializer_list 이면 아래처럼 전달가능
	foo( {1,2,3,4,5});
	foo( {1,2,3} );
}