// 5_반복자1
#include <iostream>
#include <vector>
#include <list>

int main()
{
//	std::list<int>   c = { 1,2,3,4,5,6,7,8,9,10 };
	std::vector<int> c = { 1,2,3,4,5,6,7,8,9,10 };

	// 컨테이너 모든 요소 열거하는 방법
	// => range-for 사용하세요
	for( auto e : c )
	{
		std::cout << e << std::endl;
	}
	// 위 코드의 원리!!!
	// => 결국 반복자를 꺼내는것. 
	// => 위코드를 컴파일러는 아래 코드로 변경
	auto first = c.begin(); // 배열이면 배열 이름
	auto last  = c.end();   // 배열이름 + 크기

	for( ;first != last; ++first)
	{
		auto e = *first; 
		//----------------------------
		std::cout << e << std::endl;
	}
}

