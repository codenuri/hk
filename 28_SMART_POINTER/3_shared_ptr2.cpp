#include <iostream>
#include <memory>


void* operator new(size_t sz)
{
	std::cout << "new : " << sz << std::endl;
	return malloc(sz);
}

struct Point
{
	int x, y;

	Point(int a = 0, int b = 0) : x(a), y(b) {}
};

int main()
{
	// 아래 코드는 동적 메모리 할당을 몇번하게 될까요 ?
	// => 2번 할당
	// 1. 사용자 코드인 new Point(1,2)
	// 2. shared_ptr 생성자에서 control block(참조계수) 생성
//	std::shared_ptr<Point> sp( new Point(1, 2) );

	// 아래 처럼 하면 std::make_shared 가
	// 1. sizeof(Point) + sizeof(control block) 을 한번에 할당하고
	// 2. 해당 객체를 관리하는 shared_ptr 반환	
	std::shared_ptr<Point> sp = std::make_shared<Point>(1,2);
	

	// Point 객체를 생성해서 스마트 포인터로 관리할때
	std::shared_ptr<Point> sp1 = new Point(1, 2); // error. explicit 생성자
	std::shared_ptr<Point> sp2(  new Point(1, 2)); // ok. 권장안함
	std::shared_ptr<Point> sp3 = std::make_shared<Point>(1,2); // ok. best
}
