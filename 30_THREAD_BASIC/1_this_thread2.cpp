#include <iostream>
#include <thread>
#include <chrono>
using namespace std::literals;

int main()
{
	// sleep_for : 현재 스레드 재우기
	// => 인자는 chrono 라이브러리의 타입으로 해야 합니다.
//  std::this_thread::sleep_for(3);	// error

	std::chrono::seconds s(3);
	std::this_thread::sleep_for(s); // ok

	std::this_thread::sleep_for( std::chrono::seconds(3) ); // ok
	std::this_thread::sleep_for( 3s); // user define literal 문법 
}

