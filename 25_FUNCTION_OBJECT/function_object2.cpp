#include <iostream>
#include <vector>
#include <algorithm>

// 함수객체의 장점 1. Closure

bool foo(int n) { return n % 3 == 0; }

int main()
{
	std::vector<int> v = { 1,2,6,5,4,3,7,8 };

	// 주어진 구간에서 "3의 배수"를 찾고 싶다. 
	auto p1 = std::find_if(v.begin(), v.end(), foo);


	int k = 3; // 사용자가 입력한 값이라고 가정

	// 주어진 구간에서 "k의 배수"를 찾고 싶다. 
	// => 위 foo 에서 "% 3" 대신 "% k" 해야 하는데 
	// => foo에서 main 의 지역변수 접근할수 없습니다.
	auto p2 = std::find_if(v.begin(), v.end(), ?);
	
}



