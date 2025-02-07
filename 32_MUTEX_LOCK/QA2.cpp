#include <string_view>
#include <string>

void f1(const std::string& s) {} // C++17 이전 best, C++17 이후 best 아님



void f2(std::string_view sv) {} // C++17 이후 best

int main()
{
	std::string s1 = "AAA";

	// 아래 2줄은 별차이 없습니다.
	f1(s1);
	f2(s1);

	// 아래 2줄이 핵심 입니다.
	f1("hello");	// "hello" => std::String 임시객체 생성(문자열도 힙에 복사)
					// 전달
	f2("hello");	// 상수 메모리에 있는 문자열을 sv가 가리키게 됩니다.
	
}


