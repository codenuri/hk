#include <iostream>
#include <string>

// 아래 코드 평가해 보세요
// => 복사에 의한 swap
// => 느립니다.
template<typename T>
void Swap(T& a, T& b)
{
	T tmp = a;
	a = b;
	b = tmp;
}

// 이동에의한 swap 
// => 빠릅니다.
template<typename T>
void Swap(T& a, T& b)
{
	T tmp = std::move(a);
	a = std::move(b);
	b = std::move(tmp);
}

int main()
{
	std::string s1 = "AAA";
	std::string s2 = "BBB";	
	Swap(s1, s2);
}
// 핵심 : 알고리즘 작성시, 복사를 할지 이동을 할지 잘 선택하세요
// => 적절히 std::move 를 사용한다면 아주 빨라집니다.

// => 즉, 이동생성자를 만드는 법을 이해 하지 못해도

// => std::move 를 사용하는 것을 반드시 알아야 합니다.