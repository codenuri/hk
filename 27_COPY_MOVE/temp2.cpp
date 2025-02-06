class Point
{
	int x, y;
public:
	Point(int x, int y) : x{x}, y{y} { }
	~Point()                         { }
};

int main()
{
	// 임시객체 와 레퍼런스 규칙 - 외우세요
	
	// non-const reference 로는 임시객체를 가리킬수 없다.
	Point& r1 = Point{1,1}; 		// error



	// const reference 는 임시객체를 가리킬수 있다.
	const Point& r2 = Point{1,1}; 	// ok
					// 이순간 임시객체의 수명이 r2의 수명으로 연장됩니다.
					// life extension 이라는 개념

	// 그런데, C++11 을 만들때
	// => 상수성 없이 임시객체를 가리키는 참조가 필요 했다.
	// => 이유는 move 배울때 설명
	// => rvalue reference 
	Point&& r3 = Point{1,1}; // ok
							 // 역시 life time extension 발생!

}






