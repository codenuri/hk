#include <iostream>

// 139 page , 147 page
class Animal
{
public:
	void Cry1() { std::cout << "Animal Cry1" << std::endl; } // 1
};

class Dog : public Animal
{
public:
	// function override : 기반 클래스 멤버 함수를 파생 클래스에서 다시 구현하는 것
	// 
	// overloading 과 잘 구별 하세요 : square(int), square(double)

	void Cry1() { std::cout << "Dog Cry1" << std::endl; }  // 2
};

int main()
{
	Animal a; a.Cry1(); // 1. "Animal Cry1"
	Dog    d; d.Cry1(); // 2. "Dog Cry1"


	Animal* p = &d;		

	// 실제 객체 : Dog
	// p 의 타입 : Animal*
	p->Cry1(); //  객체가 Dog 이므로 논리적으로는 Dog Cry1 이 맞다!!
				// C++, C# : Animal Cry1
				// Java, Swift, kotlin, python : Dog Cry1 

}

// p->Cry1() 을 어떤 함수로 연결할것인가 ? 
// => 함수 바인딩(function binding) 이라고 합니다.
// => 2가지 기술이 있습니다.

// 1. static binding : 컴파일 시간에 컴파일러가 결정해야 한다.
//					   "p->Cry1()" 에서 컴파일 시간에 컴파일러는 p가 가리키는
//					   실제 객체의 타입 알수 없다.
//					   컴파일러가 아는 것은 p 자체의 타입인 Animal*
//					   그래서, 컴파일러가 함수 호출을 결정하면
//					  p의 포인터 타입에  따라 "Animal Cry1" 호출
// 논리적이지 않지만 빠르다
// C++, C#

// 2. dynamic binding : 컴파일시간에는 p 가 가리키는 메모리를 조사하는 기계어 코드생성
//					실행시 메모리를 조사해서 함수 호출을 결정
//					p가 가리키는 곳에 Dog 객체가  있었다면 Dog Cry1() 호출
// 논리적이지만 느리다.
// Java, Python, Swift, Kotlin
// C++/C# virtual function 



