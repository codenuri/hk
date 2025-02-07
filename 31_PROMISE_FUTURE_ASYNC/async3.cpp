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
int main()
{
//	std::future<int> ft = std::async(&add, 1, 2);

	// async 의 결과를 받지 않으면
	// => 리턴된 임시객체는 다음 문장으로 가기전에 파괴됩니다.
	// => 이때 std::future<int> 의 소멸자가 내부적으로 get() 을 호출해서
	// => 스레드 종료를대기하기 됩니다.
	// => 따라서 동기 호출 처럼 보이게 됩니다.
	// => 결론 : std::async 사용시는 반드시 리턴값 받으세요
	std::async(&add, 1, 2);

	std::this_thread::sleep_for(1s);
	std::cout << "continue main\n";

//	int ret = ft.get(); // 이순간 대기!
}
// 실행결과 예측하세요(화면 출력력)
