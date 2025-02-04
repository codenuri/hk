#include <iostream>



// 날짜를 다루는 타입을 설계해 봅시다.
class Date
{
private:
	int year;
	int month;
	int day;
	
	static int days[12];

//	static int days[12] = {31, 28, 31, 30, 30, 30, 30, 30,	30, 30, 30, 30};

public:
	Date(int y, int m, int d) : year{y}, month{m}, day{d} {}

	// getter/setter
	int get_year() const { return year;}

	void set_year(int y) { if ( y > 0 ) year = y; }

	Date after_days(int ds)
	{
		Date temp{year, month, day + ds}; // 잘못된 구현

		return temp;
	}
};
int Date::days[12] = {31, 28, 31, 30, 30, 30, 30, 30,	30, 30, 30, 30};



int main()
{
	Date today{2025, 2, 4};


	Date d = today.after_days(1000);

	// 5월이 몇일 까지 있는지 알고 싶다.
	// 방법 #1. 객체를 만들어서 함수를 호출 하게 하자.
//	Date d1{1,1,1};
//	int n = d1.how_many_days(5);

	// 방법 #2. 객체 없이 함수를 호출하게 하자. 
	// => 5월이 몇일인지 아는것은 기준일이 필요 없다.!!!
	// => static 멤버함수가 좋다.
	int n = Date::how_many_days(5);

	//----------------------------------
	// 내일의 날짜를 알고 싶다.
	// => "내일"의 개념은 기준일이 필요하다.
	// => 객체 생성후 호출하도록 해야 한다
	// => non-static 멤버 함수
	Date d3{2025, 2, 4};
	Date d4 = d3.tomorrow();

	//-----------------------------
	// 윤년인지 조사하고 싶다.
	// => 이 멤버 함수는 아래 2개 버전을 모두 제공하는 것이 좋습니다.
	// 방법 #1. non-static
	Date d5{2025, 2, 4};
	bool b1 = d5.is_leap_year();

	// 방법 #2. static
	bool b2 = Date::is_leap_year(2025);
}