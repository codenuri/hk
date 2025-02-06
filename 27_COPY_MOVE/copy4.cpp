#include <string>
#include <vector>

int main()
{
	// 아래 클래스들은 모두 내부적으로 포인터가 있고
	// 동적 메모리 할당하는 코드가 있습니다.
	// => 모두 복사 생성자가 만들어져 있고,
	//    깊은 복사로 구현되어 있습니다.
	std::string s1 = "hello";
	std::string s2 = s1;		// 이순간 std::string 복사생성자 호출
								// 깊은 복사로 구현

	std::vector<int> v1(10,2);
	std::vector<int> v2 = v1;	// 이순간 std::vector 복사생성자 호출
								// 깊은 복사로 구현
}