#include <iostream>

// this 활용

class Point
{
	int x, y;
public:
	// #1. 이름 충돌시 멤버임을 명확히 나타내기 위해서
	void set(int x, int y) 
	{
		this->x = x;	

	}
	// #2. this 를 반환
	Point* foo() { return this; }
};
int main()
{
	Point p1;
	p1.set(10, 20);

	// this를 반환하면 연속적인 함수 호출 가능
	// => cout 원리
	p1.foo()->foo()->foo();

	std::cout << "A" << "B" << "C";
//	std::cout.operator<<("A").operator<<("B").oprator<<("C");
}
