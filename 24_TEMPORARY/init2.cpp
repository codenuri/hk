// init1.cpp
#include <initializer_list>
#include <iostream>

// std::initilizer_list 는 생성자에 사용하려고 만들었습니다.
class Point 
{
public:
	Point(int)      { std::cout << "int\n";}						// 1
	Point(int, int){ std::cout << "int, int\n";}					// 2
	Point(std::initializer_list<int> e) { std::cout << "initializer_list\n";}// 3
};
int main()
{	
	// 아래 코드가 각각 어떤 생성자 를 호출할지 생각해 보세요
	Point p1(1);		// 1
	Point p2(1,1);		// 2
	Point p3({1, 1});	// 3
	//---------------------------------
	Point p4{1, 1}; 	// {} 초기화 로 사용하는 객체는아래 규칙 입니다.
						// (1) std::initilizer_list 버전을 우선 선택
						// (2) (1)이 없다면 int, int 생성자 호출

	Point p5(1, 2, 3); // error. int 3개 생성자는 없다

	Point p6{1, 2, 3}; // ok. std::initializer_list 생성자
	Point p7 = {1, 2, 3}; 

	// 생성자 인자로 std::initializer_list 가 있다면 {} 초기화로 몇개라도전달가능
	// 그래서 아래 코드가 C++11 에서 부터 가능했던것
	std::vector<int> v1 = {1,2,3,4};	
	std::vector<int> v2{1,2,3,4};	

	// 아래 2줄 차이점 해석하세요
	std::vector<int> v3(10, 2); // 10개 요소를 2로 초기화. v3.size()는 10
	std::vector<int> v4{10, 2}; // 2개 요소를 10, 2로 초기화. v4.size()는 2
}

// 결론 생성자 인자로 std::initializer_list 를 사용하지 않은 타입이면
// 아래 2줄은 동일
Point p1(1,2);
Point p2{1,2};

// 결론 생성자 인자로 std::initializer_list 를 사용하는 타입이면
std::vector<int> v1(10,2);
std::vector<int> v2{10,2};
