#include <iostream>

// 가상함수 원리   
// 149 page..

class Animal
{
	int age;
public: 
	virtual void cry() {}
	virtual void run() {}
};
//--------------------
class Dog : public Animal
{
	int color;
public:	
	void cry() override {}
};

int main()
{
	Animal a;
	Dog    d;

	Animal* p = &d;
	p->cry();	
	// 1. p 가리키는 곳을  실제 객체가 무엇인지 조사
	// 2. 객체에 따라 함수 호출

	// 그런데!!
}


