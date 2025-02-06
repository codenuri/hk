#include <string>

// 클래스가 내부적으로 포인터가 있으면
// => 소멸자, 복사 생성자, 이동생성자 모두 만들어야 합니다.

// raw pointer 대신 STL 사용했다면(std::string, std::vector)
// => 소멸자, 복사 생성자, 이동생성자 모두 안만들어도 됩니다.
// => 없는게 아니고, 모두 컴파일러가 지원 
// => 최선의 코드!

class People1
{
	char* name;
public:
	People1(const char* s)
	{
		name = new char[strlen(s)+1];
	}
};

class People2
{
	std::string name;
public:
	People1(const std::string& name) : name{name} {}
};