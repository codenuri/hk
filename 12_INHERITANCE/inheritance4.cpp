#include <iostream>

// 핵심 : 기반 클래스인 Base 에 디폴트 생성자가 없습니다.
// => 아래 코드에서 에러를 모두 찾아 보세요. 

class Base
{
public:
	Base(int a) { std::cout << "Base(int)" << std::endl; }
	~Base() { std::cout << "~Base()" << std::endl; }
};

class Derived : public Base
{
public:
	// 기반 클래스에 디폴트 생성자가 없으므로 아래 코드는 모두 에러
//	Derived()      {}  // call Base::Base()
//	Derived(int a) {}  // call Base::Base()

	// 컴파일러에게 기반 클래스의 다른 생성자를 호출하는 코드를 만들라고 하려면
	// => 초기화 리스트 문법 사용
	Derived()      : Base(0) {}  // call Base::Base(int)
	Derived(int a) : Base(a) {}  // call Base::Base(int)

};

int main()
{
}




