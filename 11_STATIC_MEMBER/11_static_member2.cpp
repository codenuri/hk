#include <iostream>

// 106page ~

// 방법 2. 전역변수
// => 전역변수는 오직 한개만 만들어지고 모든 자동차 객체가 공유할수 있다.
// => 객체의 갯수 파악 성공

// 그런데..
// => 전역변수는 어디서나 접근 가능하다.
// => 안전하게 하기 위해 private 으로 보호할수 없을까 ??

int cnt = 0;

class Car
{
	int color = 0;
public:	
	Car()  { ++cnt;}
	~Car() { --cnt;}
};

int main()
{
	Car c1;
	Car c2;

	cnt = 100;

	std::cout << cnt << std::endl;	 // 2
	
}

