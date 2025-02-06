#include "chronometry.h"
#include <vector>

std::vector<int> v1;
std::vector<int> v2;
std::vector<int> v3;

void init()
{	
	constexpr int size = 10000000; // 0 6개

	v1.reserve(size);
	v2.reserve(size);
	v3.reserve(size);
	for( int i = 0; i < size; i++)
	{
		int k = rand();
		v1.push_back(k);
		v2.push_back(k);
		v3.push_back(k);
	}
}
//-------------------------------------------------
// 6번에서 cmp1, cmp2, Less, Greater 모두 이곳에 복사하세요
inline bool cmp1(int a, int b) { return a < b; }
inline bool cmp2(int a, int b) { return a > b; }
struct Less   { inline bool operator()(int a, int b) { return a < b; }};
struct Greater{	inline bool operator()(int a, int b) { return a > b; }};

void ex1()
{
	std::sort(v1.begin(), v1.end(), cmp1);
	std::sort(v1.begin(), v1.end(), cmp2);
}
void ex2()
{
	Less f1;
	Greater f2;
	std::sort(v2.begin(), v2.end(), f1);
	std::sort(v2.begin(), v2.end(), f2);
}

void ex3()
{
	std::sort(v3.begin(), v3.end(), [](int a, int b) { return a < b;});
	std::sort(v3.begin(), v3.end(), [](int a, int b) { return a > b;});
}

int main()
{
	init();

	chronometry(ex1); // ex1 을 실행하고, 수행 시간을 화면에 출력해 달라
	chronometry(ex2); // ex2 을 실행하고, 수행 시간을 화면에 출력해 달라
	chronometry(ex3);

}

// g++ function_object8.cpp -std=c++17 


// a.exe 실행. 
// 보통 "최적화 옵션이 없으면 인라인치환이 지원되지 않습니다"
// => -O2 등의 최적화 해야 인라인 치환지원

// g++ function_object8.cpp -std=c++17 -O2  

// 참고 : chronometry 사용법
/*
chronometry(함수이름, 인자들....);

void foo(int a, double d) {}

chronometry(foo, 1, 3.4); // foo(1, 3.4) 의 수행시간 출력
*/