#include <iostream>
#include <thread>
#include <future>
#include <chrono>
using namespace std::literals;

// 스레드를 고려 하지 않은 함수
int add1(int a, int b)
{
	int s = a + b;
	return s;
}

int main()
{
	// 핵심 1. 스레드가 아닌 직접 호출은 함수의 결과를 반환값으로 받으면 됩니다.
	int ret1 = add1(1, 2);

	// 핵심 2. add1을 스레드로 수행하면 결과 얻기가 어렵습니다.
	std::thread t(&add1, 1, 2);
	t.join();

	// 다양한 테크닉으로 add1 의 결과를 꺼낼수도 있지만, 표준화된 방법이 있으면좋습니다
	// 1. promise/future
	// 2. packaged_task
	// 3. std::async

}
