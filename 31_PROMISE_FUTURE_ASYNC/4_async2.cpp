#include <iostream>
#include <thread>
#include <future>
using namespace std::literals;

int add(int a, int b)
{
	std::this_thread::sleep_for(2s);
	return a + b;
}

int main()
{
	// async 의 2가지 동작
	// 1. 스레드로 실행
	// 2. 지연실행 - 나중에 get 할때 실행해 달라.
	std::future<int> ft1 = std::async( std::launch::deffered,  &add, 1, 2); // 지연실행
	std::future<int> ft2 = std::async( std::launch::async,     &add, 1, 2); // 스레드
	std::future<int> ft3 = std::async(  &add, 1, 2); // 스레드

	int ret = ft1.get();

}
