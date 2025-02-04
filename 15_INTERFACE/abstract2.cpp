#include <iostream>
#include <vector>


class not_implmented{}; // 예외용 클래스

class Shape 
{
	int color = 0;
public:
	void set_color(int c) { color = c;}

	// 가상함수     : 파생 클래스가 override 하지 않으면 기본구현 제공
	// 순수가상함수 : 파생 클래스에게 반드시 구현을 제공하라는 의도

//	virtual void draw() { std::cout << "draw shape\n";}
	virtual void draw() = 0;

//--------------------------------------------------
//	virtual Shape* clone() const = 0;

	// clone 도 "=0" 으로 해도 되는데, 
	// => 파생 클래스가 지켜야 규칙이 많아 질수 있습니다. 

	// 아래 처럼 할수도 있습니다
	// (파이썬, C#등이 많이 사용하는 기술)
	// => 기본 구현에서 예외 발생.
	// => 파생 클래스가 반드시 만들어야 하는 것은 아닙니다
	// 파생클래스가
	// 1. 구현을 다시 제공하지 않고, 사용도 하지 않으면 - ok
	// 2. 구현을 다시 제공하지 않고, 사용을 하면 - 예외 발생. 비정상 종료
	// 3. 구현을 하고 사용하면 - ok
	// => 사용할려면 구현하라는 의도
	// => 사용하지 않으면 구현안해도 된다.

	virtual Shape* clone() const { throw not_implmented();} 


	// 또는 C언어처럼
	// 기본구현에서 "면적구할수 없음" 을 나타내는 약속된 값 반환환
	virtual int get_area() const { return -1; }

};





class Rect : public Shape
{
public:
	virtual void draw() { std::cout << "draw rect\n";}

	virtual Shape* clone() const 
	{
		return new Rect(*this); 
	}
};


class Circle : public Shape
{
public:
	virtual void draw() { std::cout << "draw circle\n";}

	virtual Shape* clone() const 
	{
		return new Circle(*this); 
	}
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

			v.push_back( v[k-1]->clone() );
		}
	}
}



