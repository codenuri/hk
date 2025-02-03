#include <iostream>

// 동일이름의 상수/비상수 함수를 동시에 제공가능합니다.
class Test
{
public:
	void foo()       { std::cout << "foo" << std::endl; }			// 1
	void foo() const { std::cout << "foo const" << std::endl; }		// 2
};

int main()
{
	const Test ct;
	ct.foo();	

	Test t; 
	t.foo();	
}

