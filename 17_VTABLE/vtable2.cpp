#include <iostream>

// 클래스가 가상함수가 있으면 컴파일러가 아래 배열을 생성합니다

void* animal_vtable[] = {animal_type정보, &Animal::cry, &Animal::run};

class Animal
{
	void* vtptr = animal_vtable; // 컴파일러가 추가한 멤버
								 // sizeof(animal) 는 "int + 포인터 크기"
	int age;
public: 
	virtual void cry() {}
	virtual void run() {}
};




//--------------------
void* dog_vtable[] = {dog_type정보, &Dog::cry, &Animal::run};

class Dog : public Animal
{
	void* vtptr = dog_vtable;
	int color;
public:	
	void cry() override {}
};

int main()
{
	Animal a1, a2;

	Dog    d;

	Animal* p = &d;
	p->cry();	

	// p->vtptr[1]() 라는 의미의 기계어 코드 생성 

}

// 가상함수 오버헤드

// 메모리
// 1. 클래스당 한개의 가상함수 테이블
// => 가상함수가 1000개면 4K(8K) 정도
// => 객체당 포인터 한개 추가

// 성능
// 1. 결국 주소를 2번이상 따라가서 호출
// => 약간의 성능저하

// 2. 가상함수는 인라인 치환이 될수 없다.
//    아무리 간단해도 인라인으로 할수 없다.