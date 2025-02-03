#include <iostream>

// static_cast : 논리적으로 맞고 위험하지 않은 경우만 허용
//          void*=> 다른 타입*,
//			상속관계의 캐스팅 등.
//          반드시 연관성이 있어야 한다


int main()
{
	double d = 3.4;

	// #1. 표준 타입 끼리의 변환
	int    n = d;

	// #2. void* => 다른타입* 변환
	int* p1 = malloc(100);    


	// #3. int* => double* 
	double* p2 = &n;
}

