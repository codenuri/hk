#include <iostream>
#include <bitset>
#include <algorithm>

template<int N = 10>
class URandom   // unique random
{
	std::bitset<N> bs; // 비트를 관리하는 C++ 표준타입
	bool recycle = false;
public:
	URandom(bool b = false ) : recycle{b} {}

	URandom()
	{
//		bs.set(0); // 0번째 비트만 1
		bs.set();  // 모든 비트를 1
	}
	int operator()()
	{
		if ( bs.none() ) // 모두 0이면
		{
			if ( recycle == true )
				bs.set(); // 다시 모두 1로 
			else 
				return -1; // 더이상 난수 없다.
		}


		int k = -1; 
		
		while( !bs.test( k = rand() % N) );

		bs.reset(k);

		return k;
	}
};



//URandom random; // 이제 random 은 함수가 아닌 "객체" 입니다.
				// 하지만 () 연산자를 재정의 했으므로 
				// 3-1.cpp 의 "random 함수와 동일하게 사용가능합니다."



int main()
{
//	URandom random(true); // 0 ~9 모두 반환하면 
						  // 다시 0~9 사용가능. 

	URandom<100> random(true);   // 0 ~ 99 

	for( int i = 0; i <15; i++)
	{
		std::cout << random() << std::endl;
	}
//	random.reset(); // 내부적으로 bs.set() 


	// C++20 부터 새로나오는 표준라이브러리는 함수가 아닌 함수 객체 입니다.
	int n1 = std::ranges::max(1,2); // 함수 아닙니다.
	int n2 = std::ranges::max.operator()(1,2); // 함수객체 입니다.
}