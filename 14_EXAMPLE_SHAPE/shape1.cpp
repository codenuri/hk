#include <iostream>
#include <vector>

// 145page ~
// 파워 포인트 같은 프로그램을 만드는 것을 생각해 봅시다.

// #1. 모든 도형을 타입으로 만드는 것이 편리하다.
// #2. 모든 도형의 기반 클래스가 있다면
// => 공통의 특징도 제공가능.
// => 모든 도형을 하나의 컨테이너에 보관할수도 있다.

class Shape 
{
	int color = 0;
public:
};

class Rect : public Shape
{
public:
	void draw() { std::cout << "draw rect\n";}
};
class Circle : public Shape
{
public:
	void draw() { std::cout << "draw circle\n";}
};

int main()
{
//	std::vector<Rect*> v;  // Rect 만 보관 가능
	std::vector<Shape*> v; // 모든 도형을 보관 가능. 
}



