#include <iostream>

// python, java, C# 의 for 문 모두 동일한 원리 입니다.

struct Point3D
{
	int x = 1;
	int y = 2;
	int z = 3;

	int* begin() { return &x;}
	int* end() { return &z + 1;}
};
int main()
{
	Point3D p;

	for( auto e : p)  // <===
	{
		std::cout << e << std::endl;
	}
}
// 에러 메세지 확인해 보세요.