#include <string_view>
#include <string>

int main()
{
	std::string s1 = "AAA";

	// #1. 아래 2줄 차이점 알아야 합니다
	std::string s2 = s1;		// 문자열 복사
								// s1, s2 는 자신의 자원 있음.
	std::string_view sv = s1;
						// sv 가 s1의 자원을 사용
						// 즉, const char* 로 생각하세요
						// 읽기만 가능.

	// #2. 아래 2줄 차이점 알아야합니다
	std::string s3 = "AAAAA";			// 힙 할당후 문자열 복사
	std::string_view sv2 = "AAAAA";		// 상수메모리를 가리 킵니다.
}