#include <vector>

// 동적 배열 개념
int main()
{
	std::vector<int> v(4, 0); // 4개를 0으로 
							  // new int[4] 로 메모리 확보

	v.resize(8); // 이순간 8개 메모리 할당!

	
}