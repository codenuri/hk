#include <iostream>
#include <memory>

void foo(void* p) { free(p); }

int main()
{
	// 삭제자 변경
	std::shared_ptr<int>  sp1(new int); // ok. sp1 소멸자가 delete 합니다.

	std::shared_ptr<int>  sp2( static_cast<int*>(malloc(40)) );
						//버그, sp2 소멸자가 free 가 아닌 delete 하므로
	
	std::shared_ptr<int>  sp3( static_cast<int*>(malloc(40)), foo );
						// ok. sp3 소멸자가 delete 가 아닌 foo 호출

}







