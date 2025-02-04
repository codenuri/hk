#include <iostream>
#include <vector>


class Shape 
{
	int color = 0;
public:
	void set_color(int c) { color = c;}

	virtual int get_area() const { return -1; }


	virtual void draw() { std::cout << "draw shape\n";}
};

class Rect : public Shape
{
public:
	virtual void draw() { std::cout << "draw rect\n";}
};
class Circle : public Shape
{
public:
	virtual void draw() { std::cout << "draw circle\n";}
};

class Triangle : public Shape
{
public:
	virtual void draw() { std::cout << "draw triangle\n";}
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
				s->draw();	
		}

		else if ( cmd == 8 )
		{
			std::cout << "몇번째 도형을 복사할까요 >> ";
			int k;
			std::cin >> k;

			// k번째 도형의 복사본을 만들어서 v 에 추가합니다.
			// 어떻게 해야 할까요 ?
			// k번째 도형을 뭘까요 ?

			// 해결책 #1. dynamic_cast 로  v[k-1] 번째 도형의 타입을 조사하자
			// => 결국 if~else 또는 switch~case 가 된다
			// => OCP 를 만족할수 없는 나쁜 디자인

			// 좋은 디자인은 다음 소스..
		}
	}
}



