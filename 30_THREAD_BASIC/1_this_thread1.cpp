#include <iostream>
#include <thread>

// <thread> 헤더안에 this_thread namespace 가 있고
// 4개의 도움 함수가 있습니다. - 2개가 널리 사용됩니다.

int main()
{
    std::cout << std::this_thread::get_id() << std::endl; // 스레드 ID 출력

	// 주의 스레드 ID 는 int 타입아닙니다 변환도 안됩니다.
    std::thread::id tid1 = std::this_thread::get_id();

}