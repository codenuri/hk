#include <iostream>

// static_cast : 컴파일 시간에 캐스팅 해달라는것
// dynamic_cast : 실행시간에 캐스팅 해달라는것

// 특수 목적 캐스팅 : reinterpret_cast, const_cast 

// static_cast : 범용적 캐스팅, 일반적인 용도로 사용
//			논리적으로 맞고 위험하지 않은 경우만 허용
//			표준 타입끼리의 변환
//          void*=> 다른 타입*,
//			상속관계의 캐스팅 등.
//          반드시 연관성이 있어야 한다

int main()
{
	double d = 3.4;

	// #1. 표준 타입 끼리의 변환
//	int    n = d;	// 암시적 변환, 경고 나올수 있음
	int    n = static_cast<int>(d); // 명시적 변환, 경고 없음



	// #2. void* => 다른타입* 변환
//	int* p1 = malloc(100);    	// C 언어는 암시적 변환도 가능. C++ 안됨
								// C++ 이면 error

	int* p1 = static_cast<int*>(malloc(100)); // ok


	// #3. 그외 상속관계의 타입캐스팅 가능. 


	// #4. int* => double* 등의 연관성없는 타입의 주소 변환
	double* p2 = (double*)&n; // ok
	double* p2 = static_cast<double*>(&n); // error

	// 의도 : 위험한 캐스팅은 "해당작업을 위한 전용 캐스팅" 을 사용해서
	//		  코드에 의도를 나타내라는 것
}

