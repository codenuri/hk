// 5_생성자1.cpp
#include <iostream>
#include <string>

class Person
{
private:
	std::string name;
	int  age;

public:
	void init( const std::string& n, int a)
	{
		name = n;
		age = a;
	}

	// 생성자 : 클래스 이름과 동일한 함수
	// => 객체를 생성하면 자동으로 호출된다.
	Person( const std::string& n, int a)
	{
		name = n;
		age = a;
	}
};
int main()
{
	// #1. 멤버 데이타가 모두 public 에 있다면 아래 처럼 초기화 가능합니다.
	// => struct 와 동일
	// => 데이타가 private 이라면 아래 코드는 에러
	// Person p = { "kim", 28 }; 

//	Person p;
//	p.init("kim", 28);

	Person p("kim", 28); // 이순간 자동으로 생성자 호출됨!


}


