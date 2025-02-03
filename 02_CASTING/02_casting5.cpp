#include <iostream>

// reinterpret_cast 
// 1. 서로 다른 타입 끼리의 주소 변환
// 2. 정수 <=> 포인터 사이의 변환

int main()
{
	int n =  10; 

	// #1. 서로 다른 타입의 주소 변환
	double* p1 = static_cast<double*>(&n);


	// #2. 정수 <=> 포인터 변환
	int* p2 = 10;

	int  n = p2;
}

