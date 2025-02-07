#include <iostream>

// C++11의 스마트포인터를 사용하려면 필요한 헤더
#include <memory>



class Car
{
public:
	void Go() { std::cout << "Go" << std::endl; }
};

int main()
{
	// 핵심 1. 생성자가 explicit 입니다. 직접 초기화만 가능합니다.
	std::shared_ptr<int> p1(new int);  // ok. 하지만 이것도 권장아님
//	std::shared_ptr<int> p2 = new int; // error.



	// 핵심 2. 스마트 포인터의 크기
	std::cout << sizeof(p1)   << std::endl; // 8  16 
											// 즉, 대부분의 환경에서
											// raw pointer 크기의 2배
											// 대상 객체를 가리키는 포인터와
											// 참조계수(control block) 포인터
	std::cout << sizeof(int*) << std::endl; // 4   8




	// 핵심 3. -> 와 . 연산자
	std::shared_ptr<Car> sp1(new Car);
	std::shared_ptr<Car> sp2 = sp1;

	// -> 연산자 : 대상체(Car객체)에 멤버에 접근하는 것
	sp1->Go();

	// . 연산자 : std::shared_ptr 자체의 멤버 함수수
	
	int n = sp1.use_count(); // 2 (참조 계수 카운트)
	
	Car* p = sp1.get();	// 스마트 포인터가 가리키는 객체의 실제 주소

	sp1.reset(); // sp1 = nullptr 과 동일
				// 참조계수를 1 빼고, 객체의 주소, cotrol block 주소를 0으로
				// 참조계수가 0이면 delete 도 책임.!
}



