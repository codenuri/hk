#include <iostream>
#include <vector>
#include <list>

int main()
{
	int x[10] = { 1,2,3,4,5,6,7,8,9,10 };

	// 배열은 연속된 메모리 이므로
	// 배열의 시작 주소를 알면 모든 요소를 열거(++ 사용)할수 있습니다
	int* p1 = x;
	++p1;

	std::list<int> s = { 1,2,3,4,5,6,7,8,9,10 };
	
	// 떨어진 메모리인 list 라도 반복자를 사용하면 ++로 이동 가능합니다
	auto it = s.begin();
	
//	++it; // 요소간 떨어진 메모리이지만
		  // ++로 다음으로 이동가능
		  // it.operator++()
	it.operator++();

	std::cout << *it << std::endl; // 2

	std::cout << sizeof(it) << std::endl; // 대부분 sizeof(포인터) 크기. 

}

