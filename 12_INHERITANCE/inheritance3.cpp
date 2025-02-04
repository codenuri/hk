#include <iostream>

class Base
{
	int data;
public:
	Base()      { std::cout << "Base()"  << std::endl; }
	Base(int a) { std::cout << "Base(int)" << std::endl; }
	~Base()     { std::cout << "~Base()" << std::endl; }
};

class Derived : public Base
{
public:
	Derived()					
	{ 
		// call Base::Base() 처럼 기반 클래스 생성자 호출 코드를 컴파일러가 추가

		std::cout << "Derived()" << std::endl; 
	} 

	Derived(int a)			
	{						
		// call Base::Base() 처럼 기반 클래스 생성자 호출 코드를 컴파일러가 추가
		// => 핵심 : 컴파일러가 추가하는 코드는 항상 기반 클래스의 디폴트(인자없는)생성자호출
		// godbolt.org 에서 기계어 확인해 보세요
		
		std::cout << "Derived(int)" << std::endl; 
	}

	~Derived()      
	{ 
		std::cout << "~Derived()" << std::endl; 

		// 소멸자는 마지막 부분에서 기반 클래스 소멸자 호출
		// call Base::~Base()
	}
};
int main()
{
//	Derived d1;		// call Derived::Derived()
	Derived d2(5);	// call Derived::Derived(int)
}




