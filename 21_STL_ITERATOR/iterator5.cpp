#include <iostream>
#include <vector>
#include <list>

// reverse_iterator
int main()
{
	std::vector<int> c = { 1,2,3,4,5,6,7,8,9,10 };

//	auto p1 = c.begin(); 
//	auto p2 = c.end();

	auto p1 = c.rbegin();  // 뒤에서 1번째
	auto p2 = c.rend();	   // 제일 앞의 앞쪽
							// 이동방향은 <-  으로


	while (p1 != p2)
	{
		std::cout << *p1 << ", ";
		++p1;
	}
	std::cout << std::endl;

}

