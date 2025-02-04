class Car
{
	int color;
	static int cnt;
public:
	// 핵심
	// static member data     : 객체가 없어도 메모리에 있다
	// static member function : 객체없이 호출 가능

	// 다음중 에러를 모두 골라 보세요
	void foo()	
	{
		color = 0;	// 1. ok
		cnt = 0;	// 2. ok
		goo();		// 3. ok

		std::cout << this; // 4. ok
	}
	// 핵심 : static 멤버 함수 안에서는 static 멤버만 접근 가능하다.
	static void goo()	
	{
		color = 0;	// 5. error
		cnt = 0;	// 6. ok
		foo();		// 7. error

		std::cout << this; // 8. error
	}
};
int Car::cnt;

int main()
{
	Car::goo(); 
}
