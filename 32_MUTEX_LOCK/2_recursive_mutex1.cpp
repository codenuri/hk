#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
using namespace std::literals;

//std::mutex m;
std::recursive_mutex m;	// 연속적으로 2회 이상의 lock/unlock 가능.

// C++ 에는 총 4개의 mutex 가 있습니다.
// std::mutex : 연속 2회 안됨	      =>>> 이게 중요
// std::recursive_mutex : 여러번 가능
// std::shared_mutex				 =>>> 성능향상에 중요
// std::timed_mutex

int share_data = 0; // 파일 이라고 가정해 보세요(공유자원원)

void foo()
{
    m.lock();
	m.lock();

    share_data = 100;
    std::cout << "using share_data" << std::endl;

    m.unlock();
	m.unlock();
}
int main()
{
    std::thread t1(foo);
    std::thread t2(foo);
    t1.join();
    t2.join();
}




