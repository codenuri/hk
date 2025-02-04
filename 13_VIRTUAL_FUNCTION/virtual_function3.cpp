#include <iostream>

// 이번 예제 반드시 이해해야 합니다다

// C++ 사용시 "상속 문법" 을 사용한다면
// => 반드시 기반 클래스 소멸자를 "virtual" 로 하세요!!!

// => 단, 소멸자가 하는 일이 없고, delete Base* 형태의 코드를 사용하지 않으면
//    문제가 되진 않습니다.

//    그런데, 안전하게 하려면 "virtual 소멸자" 로 하세요


class Base
{
public:
	Base()  {  }
//	~Base() {  }	
	virtual ~Base() {  }	
};

class Derived : public Base
{
public:
	Derived()  { std::cout << "Derived() 자원할당" << std::endl; }
	~Derived() { std::cout << "~Derived() 자원해지" << std::endl; } // ~Base()
};

int main()
{
//	Derived d;	// 아무 문제 없음

//	Derived* p = new Derived;	
//	delete p;	// 아무 문제 없음

	Base* p = new Derived;	
	
	delete p;		// 이순간 소멸자를 호출해야 하는데..
					// p->소멸자()

	// 소멸자 호출도 함수 호출입니다.!

	// 컴파일러의 원리
	// 1. static binding 할지 dynamic binding 할지 결정해야 합니다.
	// 2. 컴파일러는 p의 타입이 Base* 라는 것만 안다.
	// 3. Base 클래스에서 소멸자가 virtual 인지 조사.

	// 4. Base 소멸자가
	// virtual     : dynamic binding 이므로 어떤 객체인지 조사후 소멸자 선택 
	// non-virtual : static binding 이므로 무조건 ~Base() 호출

}

// chcp 650001




