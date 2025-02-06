#include <iostream>
#include <vector>
#include <algorithm>

// 함수객체의 장점 1. Closure

// 일반 함수는 "상태가 없고", "동작만 있다"
// => 함수 실행중에 생성된 데이타를 보관할 장소가 없다.

// 함수 객체는 상태를 가질수 있습니다.
// => 멤버 데이타가 있다는 의미.. 

bool foo(int n) 
{
	 return n % 3 == 0; 
}



class IsDivide
{
	int value;
public:
	IsDivide(int n) : value{n} {}

	bool operator()(int n) 	// bool operator()(IsDivide* this, int n)
	{ 
		return n % value == 0;
	}
};

int main()
{
	std::vector<int> v = { 1,2,6,5,4,3,7,8 };
	int k = 3; 

	IsDivide f(k); // f 객체는 내부적으로 k의 값을 보관하게 됩니다.
	bool b = f(10); // f는 () 연산자가 재정의 되어서 함수 처럼 사용가능합니다
					// 10 % value(k) 의 의미 입니다.

					// 즉, f 는 k의 값을 보관하고 있는 "단항 함수" 입니다.

	auto p1 = std::find_if(v.begin(), v.end(), f);
	
}



