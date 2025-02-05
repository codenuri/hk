#include <iostream>
#include <vector>

class Point
{
	int x, y;
public:
	Point( int a, int b) : x(a), y(b) 
	{
		std::cout << "Point()\n";
	}
};
int main()
{
	std::vector<int> v1(1000); // size = 1000, capacity = 1000

	std::vector<int> v2;	// size = 0 capacity = 0
	v2.reserve(1000);		// size = 0 capacity = 1000

	v1.push_back(0); // 1001 번째 넣기
	v2.push_back(0); // 1 번째 넣기

//	std::vector<Point> v3(100); // 실행결과 예측(화면출력 결과)
								// 100개 요소(size)
								// 100번의 Point 생성자 호출
								// 하지만 Point 는 디폴트 생성자가 없어서 error

	Point p(1,1);
	std::vector<Point> v3(100, p); // p 를 복사해서 100개 만들어 달라	
									// 즉, 복사 생성자 사용

	std::vector<Point> v4;
	v4.reserve(100);	// 메모리만 확보합니다.
						// 생성자가 호출되지 않습니다.
	
//	v4.resize(5); 	// 이순간 확보되었던 메모중 5개에 대해서
					// 생성자만 호출됩니다.(placement new 문법)
	v4.resize(5, p);				
}
