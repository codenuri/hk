// 4_접근지정자1 - 74page
#include <iostream>
#include <string>

struct Person
{
	std::string name;
	int  age;	
};

int main()
{
	Person p;
	p.name = "kim";
	p.age = -10; // 사용자가 실수 했다.				 
}
