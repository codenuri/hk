#include <iostream>
#include <thread>
#include <chrono>
#include <string_view>
#include <mutex>
using namespace std::literals;

void delay() { std::this_thread::sleep_for(20ms); } // 시간지연

// 아래 함수는 여러개 스레드가 동시에 실행해도 안전합니다.
// => thread-safe 하다 라고 합니다.
/*
void foo(std::string_view name)
{
    int x = 0;	// 지역변수, 스택에 놓이고, 스택은 스레드당 한개

    for (int i = 0; i < 10; i++)
    {
        x = 100;   delay();
        x = x + 1; delay();
        std::cout << name << " : " << x << std::endl; delay();
    }
}
*/
// 아래 코드는 스레드 safe 하지 않습니다.
// => 함수 안에서 모든 스레드가 공유하는 자원을 사용하는 경우
// => 아래 x를 화일이라고 생각해 보세요
void foo(std::string_view name)
{
    static int x = 0;	 // static 지역변수 또는 전역변수는 데이타(static) 메모리에 
						 // 있습니다.
						 // => 프로세스당 한개, 즉, 모든 스레드가 공유 합니다.

    for (int i = 0; i < 10; i++)
    {
        x = 100;   delay();
        x = x + 1; delay();
        std::cout << name << " : " << x << std::endl; delay();
    }
}

int main()
{
    std::thread t1(foo, "A");
    std::thread t2(foo, "\tB");
    t1.join();
    t2.join();
}



