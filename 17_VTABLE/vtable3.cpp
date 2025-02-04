#include <iostream>

class A
{
	int a;
public:
	void foo() { std::cout << "foo" << std::endl; }		// 1
};
class B  
{
	int b;
public:
	void goo() { std::cout << "goo" << std::endl; }		// 2
};

int main()
{
	A aaa;

//	B* p = &aaa;	// error
	B* p = reinterpret_cast<B*>(&aaa);	// ok
	
	p->goo();  		
}
