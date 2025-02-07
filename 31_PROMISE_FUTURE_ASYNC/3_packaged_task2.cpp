#include <iostream>
#include <thread>
#include <future>

// 일반 함수라면 아래 처럼 만들게 됩니다.
// => 이미 아래 처럼 만들어진 함수를 스레드로 수행해서 결과 얻기
int add(int a, int b)
{
	return a + b;
}

int main()
{
	// #1. add 함수를 관리하는 packaged_task 객체 생성
	std::packaged_task<int(int, int)> task(add);

	// #2. 미래의결과를 담은 future 를 꺼냅니다.
	std::future<int> ft = task.get_future();

	// #3. 이제 스레드를 수행할때 task 를 수행합니다.
	std::thread t(&task, 1, 2);

	// #4. 결과가 필요하면 future 에서 꺼내세요요
	int ret = ft.get();

	std::cout << "결과 : " << ret << std::endl;

	t.join();
}




// promise & future : 함수인자로 promise 를 받아야 합니다
// 
// packaged_task    : 스레드 함수가 아닌 일반 함수 모양으로
//						만들어진 함수를 스레드로 수행해서 결과 얻기
//						"보관" 했다가 "원할때 실행"
// async : 스레드 함수가 아닌 일반 함수 모양으로
//			만들어진 함수를 스레드로 수행해서 결과 얻기
//			지금 당장 실행		


