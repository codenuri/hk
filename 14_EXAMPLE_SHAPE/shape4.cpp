#include <iostream>
#include <vector>

// 핵심 #3. 모든 도형의 공통의 특징은 반드시 Shape에도 있어야 한다.
// => 문법적 규칙은 아니지만
// => 디자인 원칙

// 핵심 #4. 기반 클래스 멤버 함수중 파생 클래스가 override 하게 되는 것은
//	        가상함수로 만들어야 한다.

class Shape 
{
	int color = 0;
public:
	// 아래 함수는 virtual 로 할까요 ? non-virtual 로 할까요 ?
	// 파생 클래스가 override 할 이유 없다. non-virtual 
	void set_color(int c) { color = c;}

	// virtual ? non-virtual ?
	// => 면적구하는 방법은 도형마다 다르다. virtual !
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
				s->draw();	// 동일한 표현식이 상황(실제 객체)에 따라
							// 다르게 동작합니다.
							// => 다형성(polymorphism)

			// OOP 언어의 3대 특징 : 캡슐화, 상속, 다형성 
		}
	}
}



