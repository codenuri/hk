#include <thread>

// copy, move

void foo() {}
void goo() {}

int main()
{
    std::thread t1(&foo);
    std::thread t2(&goo);

	// #1. swap
//	t1.swap(t2); // ok.

	// #2. copy, move
//	std::thread t3 = t1; // error

	std::thread t4 = std::move(t1); // ok

	// #3. thread 객체를 먼저 만들고, 나중에 실행
	std::thread t5;	// 스레드생성 안됨.. 단지 관리객체만 생성

//	t5 = t4; // error. 복사 및 대입 안됨

	t5 = std::thread(&foo); // 우변이 임시객체
							// 복사가 아닌 이동동

    t2.join();
    t4.join();
}

