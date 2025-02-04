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
				s->draw();	// A
		}
	}
}
// 위 코드는 왜 에러일까요 ?
// => A 부분에서 s 의 타입은 Shape* 인데, Shape 에는 draw 가 없다.

// 해결책은 뭘까요 ?
// => 다음소스에게.. 


