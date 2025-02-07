#include <iostream>

class Car
{
public:
	void Go() { std::cout << "Go" << std::endl; }
	~Car()    { std::cout << "~Car" << std::endl; }
};
// 아래 클래스가 핵심

// 스마트 포인터
// 개념 : 어떤 객체가 다른 타입의 포인터 역활을 하는 것
// 원리 : -> 와 * 연산자 재정의를 통해서 포인터 처럼 보이게 하는 것
// 장정 : raw pointer 가 아니라 "객체" 이다
//		 생성/복사/대입/소멸의 모든 과정에 추가적인 작업을 수행할수 있다.
//       대표적 활용이 소멸자에서 delete 기능수행

class Ptr
{
	Car* obj;
public:
	Ptr(Car* p = 0) : obj(p) {}

	~Ptr() { delete obj;}


	Car* operator->() { return obj; }
	Car& operator*() { return *obj; }

};
int main()
{	
	// Car* p = new Car;
	Ptr p = new Car; // Ptr p( new Car ) 로 생각하세요
					 // => 복습시 꼭 메모리 그림을 그려보세요 

	p->Go(); 	// p 는 객체인데, . 이 아닌 -> 사용
				// ( p.operator->() )Go() 의미의 코드인데
				// ( p.operator->() )->Go() 컴파일러의 이렇게 해석합니다.

	(*p).Go(); // (p.operator*()).Go()
}


