#include <iostream>
class Date
{
private:
	int year;
	int month;
	int day;

	// C++17 부터 inline static 을 사용하면 
	// static 멤버 변수의 클래스 외부 정의가 없어도 됩니다.
	inline static int days[12] = {31, 28, 31, 30, 30, 30, 30, 30,	30, 30, 30, 30};

public:
	Date(int y, int m, int d) : year{y}, month{m}, day{d} {}
};



int main()
{
	Date today{2025, 2, 4};
}