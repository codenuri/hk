// QA1-1.cpp
#include <string>
#include <iostream>


// 규칙 #3. 이동생성자만 만든 경우
// => 컴파일러는 복사 생성자를 제공하지 않는다.
// => 복사가 필요한 코드가 있다면 컴파일 에러

// 결론 
// 복사와 이동을 모두 만들거나
// 복사와 이동을 모두 만들지 말라! => 컴파일러가 모두 제공

struct People
{
	std::string name;
	People(const std::string& n) : name{n} {} 

	People(People&& p) : name{ std::move(p.name) }
	{
		std::cout << "user define move ctor\n";
	}
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

