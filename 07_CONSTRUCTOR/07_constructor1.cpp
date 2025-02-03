// 5_생성자1.cpp
#include <iostream>
#include <string>

class Person
{
public:
	std::string name;
	int  age;
};

int main()
{
	// #1. 멤버 데이타가 모두 public 에 있다면 아래 처럼 초기화 가능합니다.
	// => struct 와 동일
	Person p = { "kim", 28 }; 


}


