#include <iostream>
#include <vector>
#include <list>

int main()
{
	std::list<int>   s = { 1,2,3,4,5,6,7,8,9,10 };
	
	// 1. past the end

	auto p1 = s.begin();	// s의 1번째 요소를 가리키는 반복자
	auto p2 = s.end();		// s의 마지막이 아닌 마지막 다음을 가리키는 반복자

	*p1 = 10; // ok
//	*p2 = 10; // runtime error
			  // s.end() 로 꺼낸 반복자는 비교(==, !=)의 용도로만 사용해야 한다.
			  // * 연산은 사용금지
		  
	
	while (p1 != p2)
	{
		std::cout << *p1 << std::endl;
		++p1;
	}			  	
}