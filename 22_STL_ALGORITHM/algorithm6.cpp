#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

int main()
{
	std::list<int>   s = { 1,2,3,4,5,6,7,3,9,10 };

	// 아래 코드는 "앞 => 뒤" 순서로 검색
	auto ret1 = std::find(s.begin(), s.end(), 3);

	//"뒤 => 앞" 순서로 검색하려면 ?
	auto ret2 = std::find(s.rbegin(), s.rend(), 3);

	// std::find 같은 템플릿 기반의 함수를 C++에서 "알고리즘" 이라고 합니다.

	// reverse iterator 덕분에 "모든 알고리즘함수는 역순으로도 가능합니다."
}
