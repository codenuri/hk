#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
#include <shared_mutex>
#include <string_view>
using namespace std::literals;

// 읽을때 는 쓰면 안됩니다.
// 쓸때도 읽으면 안됩니다.
// 쓸때 동시에 써도 안됩니다.
// 읽을때는 동시에 읽어도 됩니다.  <== 핵심

//std::mutex m;
std::shared_mutex m;		// m.lock() => 나혼자 독점한다.
						 	// m.lock_shared() => 다른스레드도 lock_shared가능
							//					단 m.lock()은 안됨.

int share_data = 0;

void Writer()
{
    while (1)
    {
		{
			std::lock_guard<std::shared_mutex> g(m); 
		//	m.lock();
			share_data = share_data + 1;
			std::cout << "Writer : " << share_data << std::endl;
			std::this_thread::sleep_for(1s);
		//	m.unlock();
		}

        std::this_thread::sleep_for(10ms);
    }
}


void Reader(std::string_view name)
{
    while (1)
    {

		{
			std::shared_lock<std::shared_mutex> g(m);
		//	m.lock_shared();
			std::cout << "Reader(" << name << ") : " << share_data << std::endl;
			std::this_thread::sleep_for(500ms);
		//	m.unlock_shared();
		}

        std::this_thread::sleep_for(10ms);
    }
}

int main()
{
    std::thread t1(Writer);
    std::thread t2(Reader, "A");
	std::thread t3(Reader, "\tB");
	std::thread t4(Reader, "\t\tC");
    t1.join();
    t2.join();
	t3.join();
	t4.join();
}



