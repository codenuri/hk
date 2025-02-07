#include <iostream>
#include <thread>
#include <mutex>
#include <exception>

std::mutex m;

// 자원의 생성과 반납은 반드시 생성자/소멸자로 해야 한다.
template<typename T>
class lock_guard
{
	T& mtx;
public:
	lock_guard(T& m) : mtx(m) { mtx.lock();}
	~lock_guard()             { mtx.unlock();}
};

void goo()
{
	{
		std::lock_guard<std::mutex> g(m); // 1. 생성자에서 m.lock()
									// 2. 소멸자에서 m.unlock();
									// => 함수 실행중, 예외가 나오거나
									//    함수 중간에서 return 되어도
									//     g는 파괴되고, 소멸자 호출됩니다.
	//    m.lock();    
		
		std::cout << "using shared data" << std::endl;

	}
//    m.unlock();
}




void foo()
{
    goo();
}

int main()
{
    std::thread t1(foo);
    std::thread t2(foo);
    t1.join();
    t2.join();
}



