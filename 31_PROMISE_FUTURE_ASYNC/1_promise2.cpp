#include <iostream>
#include <thread>
#include <future>
#include <chrono>
using namespace std::literals;

// #1. 스레드 함수 만들때 promise 를 참조로 받습니다.
void add(int a, int b, std::promise<int>& p )
{
	try
	{
		int s = a + b;

		throw 1;

		// 연산의 결과가 나오면 약속 객체를 통해서 알려 줍니다.
		p.set_value(s);	// 대기중인 스레드가 깨어나서 결과를 꺼낼수 있게 됩니다.

	}
	catch(...)
	{
		p.set_exception(std::current_exception() );
	}
}

int main()
{
	// #2. 스레드 생성전에 promise 를 만들고 future 를 꺼냅니다.
	std::promise<int> p;
	std::future<int> ft = p.get_future();

	// #3. 스레드인자로 promise 객체를 참조로 전달합니다.
	std::thread t(&add, 1, 2, std::ref(p));

	std::cout << "주스레드는 다른 작업을 하다가\n";

	try
	{
		// 결과가 필요하면 future 에서 꺼내면 됩니다.
	//	ft.wait();
		int ret = ft.get(); // 결과가 있으면 꺼내오고, 없으면 결과가 나올때 까지 대기합니다

		std::cout << "결과 : " << ret << std::endl;
	}
	catch(...)
	{
		std::cout << "예외 발생\n";
	}

}
