#include <iostream>

class Point
{
	int x, y;
public:
	Point(int x, int y) : x{x}, y{y} { std::cout << "Point()\n";}
	~Point()                         { std::cout << "~Point()\n";}
};

int main()
{
//	Point pt(1, 1);	// 객체 이름이 pt
					// 이름 있는 객체(named object)
					// 이름이 있으므로 다음문장에서도 사용가능
					// 수명 : 자신을 선언한 블럭을 벗어날때 파괴.

//	Point (1, 1);	// 이름 없는 객체(unamed object)
					// 임시객체(temporary) 라고도 합니다.
					// 주의 : Point는 함수이름이 아니고 클래스이름.
					//	     따라서 함수 호출이 아니라 객체 생성입니다.
					// 이름이 없으므로 다음문장에서는 접근 안됨
					// 수명: 자신을 선언한 문장의 끝(;)


	Point(1,1), std::cout << "X\n";

	std::cout << "-----------\n";

}



