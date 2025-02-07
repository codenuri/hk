#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
using namespace std::literals;

class Machine
{
    int shared_data = 0;
//	std::mutex m;
	std::recursive_mutex m;
public:
    void f1()
    {
		m.lock();
        shared_data = 100;
		m.unlock();
    }
    void f2()
    {
		m.lock();
		// f1의 기능 필요
		f1();
        shared_data = 200;
		m.unlock();
    }
};
int main()
{
    Machine m;
    std::thread t1(&Machine::f1, &m);
    std::thread t2(&Machine::f2, &m);
    t1.join();
    t2.join();
}



