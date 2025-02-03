#include <iostream>

// 어려운 내용. 

/*
template<typename T>
T Add(T a, T  b)
{
	return a + b;
}

int main()
{
	std::cout << Add(1,   2 ) << std::endl;
	std::cout << Add(1.1, 2.2) << std::endl;

	std::cout << Add(1,   2.1) << std::endl;	// error
								// 인자를 보고 T의 타입을 결정할수 없다.
}
*/

// ? 를 채우는 것이 어렵습니다.
/*
template<typename T1, typename T2>
? Add(T1 a, T2  b)
{
	return a + b;
}

int main()
{
//	std::cout << Add<int, double>(1,   2.1) << std::endl; // 타입전달	

	// 타입인자 생략시 컴파일러가 함수 인자로 타입 추론
	std::cout << Add(1,   2.1) << std::endl; 
								
}
*/
//-------------------------------
// decltype(표현식) : 컴파일러에게 표현식의 타입을 구해달라는 요청. C++11 등장장
/*
// 아래 코드는 a, b 변수를 선언전에 사용하므로 에러 입니다.
template<typename T1, typename T2>
decltype(a+b) Add(T1 a, T2  b)	// error
{
	return a + b;
}

int main()
{
	std::cout << Add(1,   2.1) << std::endl; 

	a = 10; // error. 변수를 선언전에 사용
	int a;
	a = 10; // ok
								
}
*/

// C++11 함수 후위 반환 타입 문법
// => 리턴 타입을 함수() 뒤에 적는 기술.
/*
template<typename T1, typename T2>
//decltype(a+b) Add(T1 a, T2  b)	
auto Add(T1 a, T2  b) -> decltype(a + b)
{
	return a + b;
}

// int main()			// 전통적인 함수 모양
auto main() -> int		// 후위 반환 타입 문법
{
	std::cout << Add(1,   2.1) << std::endl; 							
}
*/

//------------------------------------------
// C++11 스타일일
template<typename T1, typename T2>
auto Add1(T1 a, T2  b) -> decltype(a + b)
{
	if ( b == 0 ) return a;
	return a + b;
}

// C++14 부터는 반환 타입 자체를 생략하고 auto 만 표기해도 됩니다.
// => return 문장을 보고 컴파일러에게 반환 타입을 추론해 달라는 것
// => 모든 return 문장이 같은 타입을 반환해야 한다.
// => 다른 타입을 반환하면 에러! 추론 안됨
template<typename T1, typename T2>
auto Add2(T1 a, T2  b)
{
	if ( b == 0 ) return a;
	return a + b;
}

auto main() -> int	
{
	std::cout << Add1(1,   2.1) << std::endl; 							
}

