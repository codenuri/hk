// 5_생성자3 - 78page ~
#include <iostream>

class Point
{
	int x;
	int y;
public:
	// 생성자
	// 1. 클래스 이름과 동일한 멤버 함수
	// 2. 리턴 타입을 표기하지 않고, 리턴할수도 없다
	// 3. 인자는 있어도 되고, 없어도된다, 여러개 만들수 있다.
	// 
	// 4. 객체를 생성하면 항상 생성자가 호출된다.
	// 
	// 5. 사용자가 생성자를 한개도 만들지 않으면
	//    컴파일러가 인자 없는 생성자를 제공한다. (디폴트 생성자)
	// 
	Point()             { x=0; y=0; std::cout << "Point()"         << std::endl; } // 1
	Point(int a, int b) { x=a; y=b; std::cout << "Point(int, int)" << std::endl; } // 2
};

int main()
{
	/*
	// #1. C++98 시절에는 아래처럼만 가능합니다.
	Point p1;			
	Point p2(1, 2);		


	// #2. C++11 부터 {} 초기화 가능합니다.
	// => 배열은 초기화 할때 {} 사용하는데, 클래스는 왜 ()를 사용하는가?
	// => 모두 {}로 사용 가능하게 하자.
	int n1 = {0}; // copy initialization
	int n2{0};    // direct initialization
				  // 차이점은 뭡니까 ? explicit 배울때 설명..
				  // ()와 {}은 항상 같습니까 ? => 다를때 있습니다. 
				  //					std::initializer_list 배울때 설명

	Point p3{ 1,2 };		// 인자 2개 생성자 호출
	Point p4 = { 1,2 };		// 위와 완전히 동일
	
*/

	// #3. 객체의 갯수만큼 생성자가 호출됩니다.
	Point arr1[5];						// 인자없는 생성자 5회 호출				
	Point arr2[5] = { {1,2},{2,3} };	// 인자 2개 생성자 2회 호출
										// 인자 없는 생성자 3회 호출

	// #4.
	Point* p;		// 객체 생성이 아닌 포인터 변수. 생성자 호출 안됨.	

	p = (Point*)malloc( sizeof(Point) ); // 메모리 8바이트 할당. 
										// 생성자 호출 안됨.	

	free(p);	// 메모리만 제거, 소멸자 호출안됨

	p = new Point;	// 메모리 할당만의 의미가 아닌 객체 생성
					// (메모리 할당 + 생성자 호출)
	delete p;		// 객체 파괴 - 소멸자 호출

	p = new Point(1, 1);	// 인자가 2개인 생성자!!
	delete p;

}