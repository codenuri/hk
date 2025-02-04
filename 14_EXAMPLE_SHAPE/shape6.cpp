#include <iostream>
#include <vector>


class Shape 
{
	int color = 0;
public:
	void set_color(int c) { color = c;}

	virtual int get_area() const { return -1; }


	virtual void draw() { std::cout << "draw shape\n";}


	// 자신의 복사본을 생성하는 가상함수는 항상 유용하게 활용됩니다.
	virtual Shape* clone() const 
	{
		return new Shape(*this); // 복사 생성자 사용
	}
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

			v.push_back( v[k-1]->clone() ); // 조사할 필요 없다.
											// 다형성
											// 새로운 도형이 추가되어도 수정안됨
											// OCP 만족

			// java 진영의 권고 : "don't ask do it"
			//					물어보지 말고 시켜라
		}
	}
}
// 리팩토링에서 유명한 용어 입니다. 이해해 보세요
// => "replace conditional with polymorphism"
//   당신의 코드에 제어문(if, switch)가 있다면 (OCP를 만족하지 못할수 있습니다.)
//   다형성(가상함수)로 변경해 보세요

//   Shape3.cpp 로 하지말고 Shape4.cpp 로 하세요. 


