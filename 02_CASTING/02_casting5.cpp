#include <iostream>

// reinterpret_cast : 메모리에 있는 데이타를 다른 방식으로 해석하겠다.
//					 그래서 이름이 "reinterpret"
// 1. 서로 다른 타입 끼리의 주소(참조) 변환
// 2. 정수 <=> 포인터 사이의 변환

int main()
{
	int n =  10; 

	// #1. 서로 다른 타입의 주소 변환
//	double* p1 = static_cast<double*>(&n);	// error
	double* p1 = reinterpret_cast<double*>(&n);	// ok

	// #2. 정수 <=> 포인터 변환
	int* p2 = 10;	// error
	int* p2 = (int*)10;	// ok. C 캐스팅은 대부분 가능.
	int* p2 = static_cast<int*>(10);	// error. 위험한 작업.
	int* p2 = reinterpret_cast<int*>(10); // ok 

	// 아래 코드는 포인터를 다시 정수로
	int  n = reinterpret_cast<int>(p2); // ok

	//--------------------------
	// reinterpret_cast 는 위 용도위에 다른 용도는 사용 불가
	int n2 = 3.4; // ok. 단, 경고 나올수 있다.
	int n2 = reinterpret_cast<int>(3.4); // error. 이 용도가 아니다.
}

