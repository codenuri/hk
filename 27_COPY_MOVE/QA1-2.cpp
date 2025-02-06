// QA1-1.cpp
#include <string>
#include <iostream>


// 규칙 #2. 복사 생성자만 제공
// => 컴파일러는 이동생성자를 제공하지 않는다.
// => std::move() 사용시 에러는 아니고, 사용자가 만든 복사생성자 사용
struct People
{
	std::string name;
	People(const std::string& n) : name{n} {} // 생성자

	People(const People& p) : name{p.name}
	{
		std::cout << "user define copy ctor\n";
	}
};

int main()
{
	People p1 = {"to be or not to be"};
	People p2 = {"to be or not to be"};

	People p3 = p1;				// 사용자가 만든 복사 생성자
	People p4 = std::move(p2);	// 사용자가 만든 복사 생성자

	std::cout << p1.name << std::endl;
	std::cout << p2.name << std::endl;
}

