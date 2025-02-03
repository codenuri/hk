#include <iostream>

int main()
{
	const int c = 10;

//	int* p = &c;	// error
	int* p = (int*)&c;	// ok. 

	*p = 20; // ok

	// 대부분 컴파일러는 아래 처럼 나오지만, 표준 아닙니다.
	// 절대 사용하면 안됩니다.
	std::cout << c << std::endl;  // 10
	std::cout << *p << std::endl; // 20 
}
