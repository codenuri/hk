#include <iostream>
#include <thread>

// 스레드 함수의 모양
void foo(int a, double d) {}

struct Machine
{
    void Run(int a, double d) {}
};
struct Work
{
    void operator()(int a, double b) const {}
};

int main()
{	
	// C++ 스레드는 일반 함수 뿐아니라 호출 가능한 모두 함수를 스레드로 수행가능
	std::thread t1(&foo, 1, 2);

	Machine m;
	std::thread t2(&Machine::Run, &m, 1, 2); // 멤버 함수

	Work w;	//함수 객체이므로 w() 처럼 호출가능

	std::thread t3(w, 1, 2); // 주의 &w 아닙니다. (&w)() 는 에러

	t1.join();
	t2.join();
	t3.join();
}
// g++ 소스.cpp -lpthread
