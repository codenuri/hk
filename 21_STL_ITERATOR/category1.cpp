#include <iostream>
#include <algorithm> // std::find 같은 알고리즘이 모두 이 헤더에
#include <list>
#include <vector>

int main()
{
	std::list<int> s = {1,3,5,7,9,2,4,6,8,10};

	std::sort(s.begin(), s.end());  // 왜 에러인지 생각해 보세요
									// 반드시 명확히 이해해야 합니다.
}