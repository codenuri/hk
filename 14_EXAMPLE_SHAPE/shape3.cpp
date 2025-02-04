#include <iostream>
#include <vector>

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
	std::vector<Shape*> v; 

	while( true )
	{
		int cmd;
		std::cin >> cmd;

		if ( cmd == 1) 		  v.push_back( new Rect);		
		else if ( cmd == 2 )  v.push_back( new Circle);
		else if ( cmd == 9 )
		{
			for( auto s : v)
			{	
				// 해결책 #1. Shape* 인 s 를 Rect 나 Circle 로 캐스팅해서 사용
				// => 조사를 위해서 dynamic_cast 사용
				if ( dynamic_cast<Rect*>(s) != nullptr )
				{
					static_cast<Rect*>(s)->draw();	
				}
				else if ( dynamic_cast<Circle*>(s) != nullptr )
				{
					static_cast<Circle*>(s)->draw();	
				}
			}
		}
	}
}

// OCP 이론
// => 기능확장에는 열려있고 (Open, 클래스가 나중에 추가되어도 )
// => 코드수정에는 닫혀 있어야(Close, 기존 코드는 수정되지 않게 하라)
// => 는 원칙(Principle)

// 위 해결책 #1 은 새로운 도형(Triangle) 이 추가되면 코드가 수정 됩니다.(추가)
// => OCP 위배하는 나쁜 디자인.


