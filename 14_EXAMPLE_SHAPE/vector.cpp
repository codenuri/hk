#include <iostream>
#include <vector>

int main()
{
	int x[5] = {1,2,3,4,5};
	
	std::vector<int> v = {1,2,3,4,5};

	// 배열과 vector 는 사용법이 유사 합니다.
	x[0] = 0;
	v[0] = 0;

	// 배열은 크기를 변경할수 없고, 멤버함수도 없습니다.
	// 하지만 vector 는 크기 변경도 가능하고, 멤버 함수도 있어서 편리합니다.
	v.resize(10);

	v.push_back(5);

	auto sz = v.size(); 
}