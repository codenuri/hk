#include <iostream>

// static member function 이야기

class Car
{
	int color = 0;
	static int cnt; 
public:	
	Car()  { ++cnt;}
	~Car() { --cnt;}

//	int get_count() const { return cnt;}
				// => 이렇게 만들면 호출하기 위해 반드시 객체가 필요하다.

	static int get_count() { return cnt;}				
				// => static 멤버 함수
				// => 객체가 없이 호출가능한 함수
				// => 클래스이름::함수이름 으로 호출
};
int Car::cnt = 0;

int main()
{

	std::cout << Car::get_count() << std::endl;


	Car c1;
	Car c2;

	std::cout << c1.get_count() << std::endl;

	
}

// static member data
// => 모든 객체가 공유하는 멤버 데이타
// => 객체가 한개도 없어도 메모리에 존재
// => 전역변수와 동일한 life cycle

// static member function
// => 객체없이 클래스 이름만으로 호출가능한 멤버 함수
