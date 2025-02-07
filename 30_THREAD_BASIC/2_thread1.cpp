#include <iostream>
#include <thread>
#include <chrono>
using namespace std::literals;

void foo()
{
    for (int i = 0; i < 10; i++)
    {
        std::cout << "foo : " << i << std::endl;
        std::this_thread::sleep_for(100ms);
    }
}

int main()
{
//  foo(); // 호출. 주스레드가 수행하는것

	std::thread t(&foo); // foo 는 다른 스레드가 실행해 달라.
						 // "t.start()" 같은 작업없이, 객체만 생성하면됩니다.

	// 주스레드가 계속 다른 작업 수행 가능

	// 스레드 생성시 반드시 아래중에 한개 해야 합니다.
	t.join(); // 스레드 종료를 대기 하거나
//	t.detach(); // 자식스레드를 떼어내기 (서로 독립되어 실행)


//	if ( t.joinable() == true )
//		t.join();
}

