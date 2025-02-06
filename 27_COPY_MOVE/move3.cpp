#include <iostream>
#include <string>
#include <vector>

int main()
{
	std::string s1 = "to be or not to be";
	std::string s2 = "to be or not to be";

	std::string s3 = s1;	// 복사 생성자호출 - 자원 복사

	std::string s4 = std::move(s2);	// 이동 생성자 호출 - 자원 이동
									// => static_cast<string&&>(s2) 이고
									// => 캐스팅 결과로 string 의 이동생성자가 호출된것
									// => 즉, string 클래스 개발자가
									//	  이동생성자를 만들어 준것

	std::cout << s1 << std::endl;	// "to be or not to be"
	std::cout << s2 << std::endl;	// ""
}