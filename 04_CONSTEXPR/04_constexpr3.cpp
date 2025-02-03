void foo()
{
	const int c = 10;

	if ( c > 20 )
	{
		// 조건이 false 이므로 실행되지 않습니다.
	}

	// C++17
	if constexpr  ( c > 20 )
	{
		// 조건이 false 이면 컴파일 하지 않습니다
	}
}