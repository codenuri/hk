#include <iostream>
#include <thread>
#include <future>
using namespace std::literals;

int add(int a, int b)
{
	std::cout << "start add\n";
	std::this_thread::sleep_for(3s);

	std::cout << "end add\n";
	return a + b;
}

std::future<int> sum_async(int a, int b)
{
	return  std::async(&add, 1, 2);
}

int main()
{
//	std::future<int> ft = std::async(&add, 1, 2);

	std::future<int> ft = sum_async(1, 2);

}
