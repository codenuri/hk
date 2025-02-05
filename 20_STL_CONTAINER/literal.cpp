// literal.cpp
#include <iostream>

class Meter 
{
	int value;
public:
	Meter(int m) : value(m) {}
};

// 한계 : 
// 1. 개발자가 직접 만들고 싶다면 "반드시 _로 시작해라"
//  => _로 시작하지 않은 것은 C++ 표준에서 예약된것.

// 2. 정수형 리터럴 접미사의 인자는 반드시 "unsigned long long" 이어야 한다.

Meter operator""_m(unsigned long long n)
{
	Meter met( static_cast<int>(n) );
	return met;
}

int main()
{
	auto a1 = 3.4; // a1 은 double
	auto a2 = 3.4f; // a2 를 float 되게 해보세요
					// 리터럴 접미사는 결국 "리터럴의 타입" 을 지정하는 것입니다.

	auto a3 = 3;  // a3 는 int

//	auto a4 = 3;  // a4 를 Meter 타입으로 만들어 봅시다.
				  // => 3을 Meter 타입이 되게 해야 합니다.
				  // => 리터럴을 사용자 정의 타입이 되게 해야 합니다

	auto a4 = 3_m; // 이순간 아래처럼 해석하기로 약속되어 있습니다.
				  // Meter operator""m(3)

	// rust
//	let v1 = 3u8; //unsigned int8 타입
//	let v2 = 3i8; // int8 타입 -> 8비트 정수

/*
	auto s1 = "aa";		// const char*
	auto s2 = "aa"s;	// std::string
	auto s3 = "aa"sv;	// std::string_view

	std::vector v1 = {"aa", "bb"}; // vector<const char*>
	std::vector v2 = {"aa"s, "bb"s}; // vector<std::string>
	std::vector v3 = {"aa"s, "bb"};  // vector<std::string>, 2번째 요소부터는
									 // const char* 을 가지고 std::String 생성
*/
}
