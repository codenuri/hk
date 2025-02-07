#include <iostream>
#include <thread>
#include <future>

// promise/future 를 사용하려면
// => 아래처럼 promise 등을 인자로 받게 됩니다.

void add(std::promise<int>& p, int a, int b)
{
	p.set_value(a + b);
}

// 그런데, 이미 만들어진 add 가 있다고 생각 해봅시다.
int add1( int a, int b)
{
	return a + b;
}


int main()
{
	std::promise<int> pm;
	std::future<int> ft = pm.get_future();

	std::thread t(add, std::ref(pm), 10, 20);

	int ret = ft.get();

	t.join();
}



