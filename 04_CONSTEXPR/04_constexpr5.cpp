// 아래 코드는 에러일까요 ? 아닐까요 ?

template<typename T>
void foo(T a)
{
	if ( false )
		*a = 10;
}

int main()
{
	int n = 0;

	foo(n);
}