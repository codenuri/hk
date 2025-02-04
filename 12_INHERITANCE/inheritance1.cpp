#include <iostream>
#include <string>

// 128 page ~

// 모든 인간의 특징을 먼저 설계
class Person
{
	std::string name;
	int age;
};

// 상속 : 기존 타입을 확장해서 새로운 타입을 설계하는 문법
class Student : public Person
{	
	int    id;
};

class Professor: public Person
{
	int    major;
};

int main()
{
	Student s;
	Professor p;
}
