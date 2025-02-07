#include <iostream>
#include <thread>
#include <mutex>
#include <exception>

std::mutex m;

void foo()
{
	std::lock_guard<std::mutex> lg(m);
	std::cout << "using shared data" << std::endl;
}

int main()
{
	std::thread t1(foo);
	std::thread t2(foo);
	t1.join();
	t2.join();
}



