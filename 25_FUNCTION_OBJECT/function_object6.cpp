// 아래 주석의 의미를 잘생각해 보세요

// 1. 일반 함수는 자신만의 타입이 없습니다.
//    signature(리턴타입과 파라미터) 가 
//    동일한 모든 함수는 같은 타입입니다.


// 2. 함수 객체는 자신만의 타입이 있습니다.
//    signature 가 동일해도 모든 함수 객체는 다른 타입입니다.


struct Less
{
	inline bool operator()(int a, int b) { return a < b; }
};
struct Greater
{
	inline bool operator()(int a, int b) { return a > b; }
};

//-----------------------------------------------------
// 비교정책을 교체할수 있고, 정책의 인라인 치환이 지원되는 함수 만들기
// => 템플릿 + 함수객체의 조합으로 만드는 기술
template<typename T>
void Sort(int* x, int sz, T cmp  )
{
	for (int i = 0; i < sz - 1; i++)
	{
		for (int j = i + 1; j < sz; j++)
		{
			if ( cmd(x[i], x[j]) == true )	
				std::swap(x[i], x[j]);
		}
	}
}

int main()
{
	int x[10] = { 1,3,5,7,9,2,4,6,8,10 };

	Less    f1; f1(1, 2); Sort(x, 10, f1); // ok. f1의 ()연산자 인라인 치환
	Greater f2; f2(1, 2); Sort(x, 10, f2); // ????
}



