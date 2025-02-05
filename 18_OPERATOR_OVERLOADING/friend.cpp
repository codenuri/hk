#include <iostream>

// friend 문법 - 75 page

class Bike
{
private:
	int gear = 0;
	
public:
//	void set_gear(int n) { gear = n; }

	// friend 함수 : 멤버는 아니지만 private 멤버에 접근할수 있게 해달라는 의미 
	// => C++ 언어만 가진 문법 
	// 1. 멤버 함수로 하면 되지 않나요 ?
	// => 멤버 함수로 만들수 없을때가 있습니다. 연산자 오버로딩등에서..
	
	// 2. getter/setter 만들면 되지 않나요 ?
	// => 모든 곳에서 접근을 허용하는 것
	// => friend 함수는 그 함수만 허용하는것
	friend void fix_bike();
};

void fix_bike()
{
	Bike b;
	b.gear = 10; // ok
}

int main()
{
	fix_bike();
}



// github.com/codenuri/hk  에서   DAY3.zip 받으시면 됩니다
