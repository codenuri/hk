#include <iostream>

int main()
{
	int* p1 = new int;	
	int* p2 = p1;

	// 사용자가 직접 메모리를 관리할때 문제점
	// #1. 메모리 누수
	// => 메모리 할당후 해지 하지 않는 문제. 

	// #2. dangling pointer
	// => 포인터가 가리키는 곳이 이미 delete 되었는데, 모르고 사용하는것
	delete p1;
	if ( p2 != nullptr )
		*p2 = 10;	// p2가 가리키는 곳이 0은 아니지만
					// 이미 삭제되었다.
					// 이런 포인터를 dangling pointer 라고 합니다.

	// #3. double delete
	delete p2; // 이미 위에서 delete 했는데, 다시 delete
				// undefined (미정의 동작 발생)
	//----------------
	// C++ 은 위와 같은 문제를 해결하기 위해서
	// => 스마트 포인터 라는 개념을 제시하고, 표준라이브러리로 제공(C++11)

}