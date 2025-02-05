#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <chrono>
using namespace std::literals; // "abc"s 사용하려면


int main()
{
	// map : key 값으로 data 보관
	std::map<std::string, std::string> m = { {"mon", "월요일"}, {"tue", "화요일"} };

	// #1. map 은 pair 를 보관합니다.
	std::pair<std::string, std::string> p1("wed", "수요일");
	auto key = p1.first; // "tue"
	auto value = p1.second; // "화요일"

	m.insert(p1);

	// #2. 
//	std::vector<int> v = {1,2,3}; 
	std::vector v = {1,2,3};  // C++17 부터 초기값있으면 int 생략가능

//	std::pair p2("thu", "목요일"); // 이렇게 하면 const char* 타입으로 추론
	std::pair p2("thu"s, "목요일"s); // 이렇게 하면 std::string 타입
									// 3.4f 개념
	m.insert(p2);

	auto m = 3min; // std::chrono::minutes m(3)
	auto s = 3us;  // literal suffix 인데
					// 학습하실때는 "user define literal " 검색해서 하시면됩니다.


	// 아래 처럼 넣어도 됩니다.
	m["wed"] = "수요일";

	std::cout << m["mon"] << std::endl; // 월요일
}





