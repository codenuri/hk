#include <thread>
#include <numeric>
#include <algorithm>
#include <functional>
#include <vector>
#include <iostream>
#include "chronometry.h" // 성능측정을 위해서..

constexpr std::size_t sz = 10000000;

std::vector<int> v;

void init()
{
	v.reserve(sz);

    for (int i = 0; i < sz; ++i)
    {
        v.push_back(i);
    }
}
//---------------------------------------------

template<typename IT, typename RT>
void sum(IT first, IT last, RT& result)
{
    result = std::accumulate(first, last, result);
}
//---------------------------------------------------------
// first ~ last 까지의 합을 구하는데, 병렬로 해달라
template<typename IT, typename RT>
void parallel_sum(IT first, IT last, RT& result)
{	
	// #1. first ~ last 사이의 요소의 갯수 구하기 
	// => last-first 의미, 그런데, - 는 vector 만 가능. 아래 코드는 list도가능
    auto cnt_element = std::distance(first, last); // last -first

    if (cnt_element == 0) return;


	// #2. H/W 적으로 코어의 갯수가 몇개 인가 ?
    std::size_t cnt_hw_thread = std::thread::hardware_concurrency();

    if (cnt_hw_thread == 0)
        cnt_hw_thread = 2;

	// #3. 한개 스레드당 최소 25개 데이타 처리
	// => 데이타가 25개 아래라면 스레드 만들필요 없다.
	// => CPU가 10개 라도 데이타가 60 개라면 ? => 스레드는 3개면 된다 

    const std::size_t cnt_per_thread = 25;

    const std::size_t max_cnt_thread =
        (cnt_element + cnt_per_thread - 1) / cnt_per_thread;

	// #4. CPU 갯수와 데이타 갯수를 고려한 최선의 갯수 결정정
    const std::size_t cnt_thread =
        std::min(cnt_hw_thread, max_cnt_thread);
	
	//---------------------------------------
	// #5. 스레드 한개당 데이타 수
	// => 60개데이타 => 최소 25개씩 처리하므로 3개 스레드 필요 한데
	// => 60개 / 3 이므로 각 스레드당 데이타는 20개
    const std::size_t block_size = cnt_element / cnt_thread;
	//---------------------------------------------------------

	// 3개스레드가 필요하면 2개 스레드만 만들면 된다. (주스레드도 계산에 포함되므로)
    std::vector<std::thread> thread_vec(cnt_thread - 1); // 스레드 객체보관관

    std::vector<RT> result_vec(cnt_thread);
				// => 각 스레드가 계산한 결과를 담을 벡터

    IT start = first;

    for (int i = 0; i < cnt_thread - 1; ++i)
    {
        IT end = std::next(start, block_size); // start + block_size

        thread_vec[i] = std::thread(sum<std::vector<int>::iterator, int>, //함수이름름
            						start, end, 	// 2개인자
									std::ref(result_vec[i])); // 마지막 인자는 참조로

        start = end;
    }

	// 마지막 구간은 주스레드 책임
    sum(start, last, result_vec[cnt_thread - 1]);


	// 모든 스레드의 종료를 대기 하고
    for (auto& t : thread_vec)
        t.join();

	// 결과 vector 의 합을 구하면 된다.
    RT ret = std::accumulate(result_vec.begin(), result_vec.end(), 0);

    result = ret;
}



int f1()
{
    // 싱글 스레드로 합을 구하기
    int s = 0;
    sum(v.begin(), v.end(), s);
    return s;
}
int f2()
{
    // 멀티 스레드로 합을 구하기
    int s = 0;
    parallel_sum(v.begin(), v.end(), s);
    return s;
}
int main()
{
    init();

    chronometry(f1); // f1의 수행시간을 출력
    chronometry(f2); // f2의 수행시간을 출력
}
