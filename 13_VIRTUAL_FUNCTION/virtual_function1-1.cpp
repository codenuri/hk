#include <iostream>
class Animal
{
public:
	// non-virtual : C++ 기본 바인딩 사용하라는 의미. static binding
	//				 즉, 호출시, 컴파일 시간에 결정하고, 포인터 타입으로 호출
	void Cry1() { std::cout << "Animal Cry1" << std::endl; } 

	// virtual : dynamic binding 해달라는 지시어
	//			 호출하면, 실행할때 메모리를 조사하게 되고, 조사 결과에 따라
	//		     함수가 결정, 객체가 Dog 라면 Dog Cry2
	virtual void Cry2() { std::cout << "Animal Cry2" << std::endl; } 
};

class Dog : public Animal
{
public:
	void Cry1() { std::cout << "Dog Cry1" << std::endl; }  

	virtual void Cry2() { std::cout << "Dog Cry2" << std::endl; }  
};



int main()
{
	Animal a;
	Dog    d; 

	Animal* p = &d;		

	p->Cry1(); // static binding 컴파일러가 결정
			   // call Animal::Cry1() 이라고 기계어 코드 생성

	p->Cry2(); // dynamic binding  실행시간 결정
				// 기계어 코드(어셈블리)에는 어느 함수로 이동하는지 알수 없다.
				// 실행해 봐야 한다.
				// call 조사결과에따라달라진함수주소.
				// 현재는 Dog 이므로 "Dog Cry2"

}

// 아래 명령으로 이 코드의 어셈을 만들수 있습니다.
// g++ 소스.cpp -S -masm=intel

// -S : 어셈블리소스 만들라는것

// -masm=intel : 형태는 인텔 어셈으로

// 결과는 .s 확장자
