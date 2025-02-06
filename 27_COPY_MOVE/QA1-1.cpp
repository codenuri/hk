// QA1-1.cpp
#include <string>
#include <iostream>

// 참고) People 자체는 자원할당 없지만, 멤버인 name 이 자원할당합니다.

// copy, move 자동생성 규칙
// 규칙 #1. copy, move 모두 만들지 않으면 컴파일러가 모두 제공한다.
// => 복사 생성자에서는 모든 멤버를 복사로!!
// => 이동 생성자에서는 모든 멤버를 이동(std::move로)

struct People
{
	std::string name;
};

int main()
{
	People p1 = {"to be or not to be"};
	People p2 = {"to be or not to be"};

	People p3 = p1;
	People p4 = std::move(p2);

	std::cout << p1.name << std::endl;
	std::cout << p2.name << std::endl;
}

