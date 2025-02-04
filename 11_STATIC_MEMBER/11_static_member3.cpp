#include <iostream>

// 106page ~

// 방법 3. static 멤버 데이타 



class Car
{
	int color = 0;
public:	
//	int cnt = 0;		// instance member data
						// => 객체당 한개씩 만들어 진다.

	static int cnt; // static member data
					// => 모든 객체가 공유.

	Car()  { ++cnt;}
	~Car() { --cnt;}
};
// static 멤버 데이타는 반드시 클래스 외부에 정의가 있어야 한다.
// 초기값도 이 위치에서 지정해야 한다.
int Car::cnt = 0;

// static 멤버 데이타 특징
// #1. 객체를 한개도 만들지 않아도 메모리에 있다.
// #2. 객체 생성시 객체의 공간에는 static 멤버 데이타는 포함되지 않는다.

int main()
{
	// 객체가 없어도 static 멤버 데이타는 접근 가능
	// 클래스이름::static멤버이름 으로 접근
	std::cout << Car::cnt << std::endl; // 0


	Car c1;
	Car c2;

	// C++에서 static 멤버 데이타 접근은
	// 1. 클래스이름::cnt - 권장. static 임을 명확히 알수 있습니다.
	// 2. c1.cnt       
	// 모두 가능합니다.
	std::cout << Car::cnt << std::endl;	 // 2
	std::cout << c1.cnt << std::endl;	 // 2

	// 2가지 방법이 있는데, 클래스 이름으로 접근을 권장할거라면
	// => 차라리 클래스 이름으로만 가능 하게 만들면 좋지 않았을까요 ?
	// => java, C#, swift 등의 대부분의 언어는 클래스 이름으로만 접근 가능.
	
}

