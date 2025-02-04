#include <iostream>

// 가상함수는 "가상함수 테이블"의 오버헤드가 있습니다.
// 그래서, delete Base* 코드를 사용하지 않는 다는 보장이 있다면
// virtual 소멸자를 사용하지 않아도 됩니다.

class Base
{
public:
	Base()  {  }

// protected 소멸자 기술
protected:
	~Base() {  }	
};
class Derived : public Base
{
public:
	Derived()  { std::cout << "Derived() 자원할당" << std::endl; }
	~Derived() { std::cout << "~Derived() 자원해지" << std::endl; } // ~Base()
};
int main()
{
	Base* p = new Derived;	
//	delete p;	// call Base::~Base()	인데, protected이므로 에러
				// p->Base::~Base()
				// Base::~Base(p)

	delete static_cast<Derived*>(p);

}





