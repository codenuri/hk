#include <string>
#include <iostream>

class Point 
{
	int x, y;
	// mutable 멤버 데이타 : 상수 멤버 함수안에서도  변경가능한 멤버 만들때 사용.
	mutable std::string cache;
	mutable bool cache_valid = false;
public:
	Point(int a, int b) : x{a}, y{b} {}

	// 객체의 상태를 문자열로 반환하는 함수 1, 2 => "1, 2"
	std::string to_string() const
	{
//		std::string s = std::to_string(x) + 
//						", " + std::to_string(y);

		if( cache_valid == false )
		{
			cache = std::to_string(x) + ", " + std::to_string(y);	
			cache_valid = true;
		}

		return cache;
	}
};

int main()
{
//	const Point p(1,2);

	Point p(1,2);

	std::cout << p.to_string() << std::endl;
	std::cout << p.to_string() << std::endl;
}
	