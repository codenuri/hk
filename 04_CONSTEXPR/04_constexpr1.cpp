// 64 page ~

// 대부분의 프로그래밍 언어에서 상수에 대한 2가지 개념

// 1. 실행시간에 값을 변경할수 없다. (immutable, readonly, runtime constant)
// => safety, optimization
// => C/C++ 의 const 키워드.
// => 초기값을 컴파일 할때 알아도 되고 몰라도 된다.
// => 변수로 초기화 가능.

// 2. 컴파일 시간에 값을 알수 있다.
// => compile-time constant 
// => 관련된 연산을 컴파일 시간에 수행할수 있다.
// => 최적화가 훨씬 잘된다.
// => C++의 constexpr 키워드.
// => 초기값으로 변수 사용할수 없다.

int main()
{
	int n = 0;

	const int c1 = n;	// ok. 변수 초기화 가능
	const int c2 = 3;	// ok. 리터럴 초기화도 가능.

	// constexpr : 컴파일 시간에 초기값을 알아야 한다.
//	constexpr int c3 = n;	// error
	constexpr int c4 = 3;	// ok 

	int k1 = c1;
	int k2 = c4;
}
// 컴파일 시간에  알면 무엇이 좋습니까 ?
// 1. 최적화가 잘되고
// 2. 컴파일 시간에 알아야만 하는 것이 있다.
// => 배열 크기, 템플릿 인자.