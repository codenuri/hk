// 아래 코드는 에러일까요 ? 아닐까요 ?
#include <type_traits>

template<typename T>
void foo(T a)
{
	// if : 실행시간 제어문
	//      컴파일 시간에 조건식이 false 라도 "템플릿 => 실제 함수" 에 포함된다.
//	if ( false )
//		*a = 10;

	// if constexpr : 컴파일 시간 제어문
	//				  조건식이 false 라면 "템플릿 => 실제 함수" 에 포함안됨.
	if constexpr( false )
		*a = 10;


	if ( std::is_pointer_v<T>)
	{
		// a 가 포인터일때 최적화된 알고리즘
	}
	else if ( std::is_integral_v<T>)
	{
		// a 가 정수 일때
	}
	else 
	{
		// 그 외의 알고리즘
	}
}

int main()
{
	int n = 0;

	foo(n);
}