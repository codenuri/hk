// 04_constexpr4.cpp

// 아래 코드에서 에러를 찾으세요. 왜 에러인지도 생각해 보세요
/*
class Test
{
	int data;
public:
	void foo()
	{
		*data = 10;	// error.  int 는 * 연산할수 없다.
	}
};
int main()
{
	Test t;
}
*/

template<typename T>
class Test
{
	T data;
public:
	void foo()
	{
		*data = 10;	
	}
};
int main()
{
	Test< int > t;
	t.foo();
}

// 지연된 인스턴스화 : 클래스 템플릿에서 사용되지 않은 멤버 함수는
//					실제 C++ class 만들때 포함되지 않는다는 의미
//					사용된 함수는 실제 "템플릿 => C++ 코드" 로 생성
