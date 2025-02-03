// constexpr 의 3가지 용도
// 1. compile-time contant - C++11
// 2. constexpr function   - C++11
// 3. if constexpr - C++17

// constexpr function
// => 함수앞에 constexpr 가 붙은 함수
// => 의미 : 실행시간에 실행될수도 있고, 컴파일 할때 실행될수도 있다.
//           인자값을 컴파일 시간에 알수 있고,
//           반환값을 컴파일 시간에 알아야 한다면
//           함수 실행을 컴파일 시간에 수행. 

	      int add1(int a, int b) { return a + b; }
constexpr int add2(int a, int b) { return a + b; }

int main()
{
	int x = 1, y = 2;

	constexpr int n1 = add1(1, 2); // error. 
	constexpr int n2 = add2(1, 2); // ok.  3

	constexpr int n3 = add2(x, y); // error. 인자값을 컴파일 할때 알수 없다

	int n4 = add2(x, y); // ok. 실행시간에 수행. 일반함수 처럼.

	int n5 = add2(1, 2); // 컴파일 시간에 수행할까요 ? 실행시간 일까요 ?
						//=> 컴파일러마다 다르지만,, 대부분 컴파일 시간


}

// 재귀 호출도 가능합니다.
int factorial(int n)
{
	return n == 1 ? 1 : n * factorial(n-1);
}

int main()
{
	constexpr int r1 = factorial(5);
}
// 위 코드만 godbolt.org 에 넣어 보세요
