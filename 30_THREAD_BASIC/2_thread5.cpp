#include <vector>
#include <thread>
#include <algorithm>
#include <functional>

void do_work(unsigned id) {}

int main()
{
    // 핵심 1. 스레드를 만들면 반드시 join(), detach() 해야 합니다.
    std::thread t1(&do_work, 1);
    t1.join();

    // 핵심 2. 10개의 스레드를 생성해 봅시다.
	// => 나중에 join 하려면 객체 어딘가 보관해야 합니다.

	std::vector<std::thread> v(10); // 10개의 스레드 객체만 생성
									// 실제 스레드는 아직 생성 안됨

	for( int i = 0; i < 10; i++)
	{
		v[i] = std::thread(&do_work, i); // 이순간 10개 스레드 생성
										 // 임시객체 이므로 move!!
	}

	for( auto& th : v)
		th.join();
}