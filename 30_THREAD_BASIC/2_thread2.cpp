#include <iostream>
#include <string>
#include <thread>

void f1() { }
void f2(int a, double d) { }
void f3(int a, int& b, std::string&& s) { b = 100; }

int main()
{
    int n = 0;
    std::string s = "hello";

     // 인자 전달 방법

	 std::thread t1(&f1);  			// 인자 없는 함수를 스레드로
	 std::thread t2(&f2, 1, 3.4);  	// f2(1, 3.4) 를 스레드로 수행
	 std::thread t3(&f3, 1, std::ref(n), std::move(s) ); 
	 								// 참조로 받고 있다면 std::ref(n) 로 전달

	t1.join();
	t2.join();
	t3.join();

}

