// 4_접근지정자1 - 74page
#include <iostream>
#include <string>

// 캡슐화(encapsulation) : 데이타는 private 에 보호해서 외부의 잘못된 사용으로
//						  객체가 불안정해 지는 것을 막는다.
//						  객체의 상태는 오직 잘 설계된 멤버 함수를 통해서만
//							변경할수 있다.





struct Person
{
private:				// 이후의 모든 멤버는 멤버 함수에서만 접근 가능하다는의미
	std::string name;
	int  age;	

public:
	void set_age(int a)
	{
		if ( a >= 0 && a < 150)
			age = a;
	}
};

int main()
{
	Person p;
	p.name = "kim";
//	p.age = -10; // 사용자가 실수 했다.		
				 // private 멤버 라면 컴파일 에러		
	p.set_age(-10); 
}
