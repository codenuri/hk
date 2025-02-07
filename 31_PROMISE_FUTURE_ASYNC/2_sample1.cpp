#include <iostream>
#include <thread>
#include <future>
#include <vector>
#include <numeric>
// 예제
int main()
{
    std::vector<int> v1 = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    std::vector<int> v2(10);

    // 작업 1. v1의 부분합을 구해서 v2에 넣기
    std::partial_sum(v1.begin(), v1.end(), v2.begin()); 

    // 작업 2. v2 의 모든 요소를 화면 출력
    for (auto n : v2)
        std::cout << n << ", ";

    // 작업 3. v2의 모든 요소의 합을 구하기
    int s = std::accumulate(v2.begin(), v2.end(), 0);
    
    // 작업 4. 결과 출력
    std::cout << "\n" << s << std::endl;
}

// 작업1 이 종료되어야만 작업2, 작업3을 할수 있습니다.
// 작업2와 작업3은 독립된 작업입니다.
// => 시간이 오래 걸리는 작업이면 2개중에 한개를 스레드로 수행해도 됩니다.


