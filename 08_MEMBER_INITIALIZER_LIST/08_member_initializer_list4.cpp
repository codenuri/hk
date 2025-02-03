#include <iostream>

// 주의 사항!
class Point
{
public:
	int x;
	int y;

	// 초기화 리스트는 대입이 아닌 초기화 입니다.
	// 멤버 데이타가 놓인 순서로 메모리에 생성되는데 
	// 생성될때 초기화하는 것 
	// 따라서 아래 코드는 코드 순서가 아닌 멤버데이타가 놓은 순서로 초기화 됩니다.
	//		  (2)    (1)
	Point() : y{0}, x{y}
	{
	}

	// 핵심 : 초기화 리스트 사용시에는 되도록 멤버데이타가 놓인 순서대로 
	//		  코드를 작성해야 합니다.
};

int main()
{
	Point pt;

	// 아래 코드의 결과를 예측해 보세요
	std::cout << pt.x << std::endl; // 쓰레기값 
	std::cout << pt.y << std::endl; // 0
}




