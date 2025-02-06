class Point
{
	int x, y;
public:
	Point(int x, int y) : x{x}, y{y} { }
	~Point()                         { }
};

int main()
{	
	Point pt{1,2};

	// 참고 : 임시객체도 등호의 왼쪽에 놓일수 없습니다.(rvalue 입니다)
	//       이름있는 객체는 lvalue 입니다.

	// 아래 규칙 외우세요

	// #1. non-const lvalue reference 는 lvalue 만 가리킨다.
	Point& r1 = pt;			// ok
	Point& r2 = Point{1,1};	// error

	// #2. const lvalue reference 는 lvalue, rvalue 모두 가능
	const Point& r3 = pt;			// ok
	const Point& r4 = Point{1,1};	// ok


	// #3. C++11 의 rvalue refernce 는 rvalue 만 가리킬수 있다.
	Point&& r5 = pt;		 // error
	Point&& r6 = Point{1,1}; // ok

	// #4. const rvalue reference 는 왜 ?? 정리 안하나요 ??
	// => rvalue 만 가리킵니다. 
	// => 그런데, 실전에서 사용하지 않습니다.
	// => 왜?? 를 이해 하려면 move 를 완벽히 알아야 합니다.

}