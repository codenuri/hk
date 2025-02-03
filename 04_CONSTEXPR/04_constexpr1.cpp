// 64 page ~

// 상수에 대한 2가지 개념
// 1. 실행시간에 값을 변경할수 없다. (immutable, readonly)
// 2. 컴파일 시간에 값을 알수 있다.
int main()
{
	int n = 0;

	const int c1 = n;
	const int c2 = 3;

//	constexpr int c3 = n;
	constexpr int c4 = 3;

	int k1 = c1;
	int k2 = c4;
}