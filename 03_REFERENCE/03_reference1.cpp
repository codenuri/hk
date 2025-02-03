// 53 page ~
#include <iostream>

int main()
{
	int  n = 10;

	int& r = n;		// r은 n의 별명(alias) 입니다.

	r = 30;        	// n = 30 과 같은 의미.

	std::cout << n << std::endl; // 30

	std::cout << &n << std::endl; // 
	std::cout << &r << std::endl; // 위와 동일한 주소. 

}



