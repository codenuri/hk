#include <iostream>

class Point
{
	int x, y;
public:
	void set(int a, int b)	// set(Point* this, int a, int b)
	{						// {
		x = a;				//		this->x = a;
		y = b;				//		this->y = b;

		// 멤버 함수안에서 this : 자신을 호출할때 사용한 객체의 주소
		std::cout << this << std::endl;
	}	

	// C++23 부터 this를 함수 인자로 명시적으로 받을수 있습니다.
	// => explicit object 파라미터라는 문법
	// => "deducing this" 라는 별명을 가진 기술
	void set2(this Point& self, int a, int b)
	{
		self.x = a;
		self.y = b;
	}					
};
int main()
{
	Point p1;
	Point p2;
	std::cout << "p1 : " << &p1 << std::endl;
	std::cout << "p2 : " << &p2 << std::endl;
	p1.set(10, 20); // set(&p1, 10, 20)
	p2.set(10, 20); // set(&p2, 10, 20)

	p1.set2(10, 20); // ok.  set2(p1, 10, 20)
}
