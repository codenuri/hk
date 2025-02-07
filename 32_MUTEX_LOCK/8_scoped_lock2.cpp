#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
using namespace std::literals;

struct  Account
{
	std::mutex m;
    int money = 100;
};

void transfer(Account& acc1, Account& acc2, int cnt)
{
	// 2개이상의 뮤텍스를 lock 할때는 "데드락 회피 알고리즘"을 사용해야 합니다.
	std::lock(acc1.m, acc2.m); // 2개를 안전하게 모두 lock
								// 단 이함수로 lock 하면
								// 직접 unlock 해야 합니다.
	
    acc1.money -= cnt;
    acc2.money += cnt;
    std::cout << "finish transfer" << std::endl;

	acc1.m.unlock();
	acc2.m.unlock();
}


int main()
{
    Account kim, lee;
    std::thread t1(transfer, std::ref(kim), std::ref(lee), 5);
    std::thread t2(transfer, std::ref(lee), std::ref(kim), 5);
    t1.join();
    t2.join();
}

