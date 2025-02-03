// 상수 함수 문법은 선택이 아닙니다.
// 필수 문법 입니다.

// 멤버 함수중 멤버 데이타의 값을 변경하지 않은 모든 멤버 함수(getter...) 는 
// "반드시" 상수함수이어야 합니다. 

class Rect
{
	int x, y, w, h;
public:
	Rect(int a, int b, int c, int d)
		: x{a}, y{b}, w{c}, h{d} {}

//	int getArea() { return w * h; } // 나쁜 코드가 아닌 틀린 코드
	int getArea() const { return w * h; }

};

//void foo(Rect r)	   // call by value 복사본의 오버헤드가 있다.
void foo(const Rect& r)
{
	int n = r.getArea();  	// ???
}

int main()
{
	Rect r(1, 1, 10, 10);	// 상수 객체 아님.

	int n = r.getArea();	// ok.. 

	foo(r);	//
}



