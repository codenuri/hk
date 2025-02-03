// 04_constexpr4.cpp

// 아래 코드에서 에러를 찾으세요. 왜 에러인지도 생각해 보세요
class Test
{
	int data;
public:
	void foo()
	{
		*data;
	}
};
int main()
{
	Test t;
}