int main()
{
	int n = 0;

	n = 3;	// ok.    n 은 lvalue : 등호의 왼쪽에 올수 있는 것
	3 = n;	// error. 3 은 rvalue

	int& r1 = n;	// ok
	int& r2 = 3;	// error. rvalue 를 reference 로 가리킬수 없다.

	// C++11 의 rvalue reference 문법 - 수요일부터 시작.. 
	// => move 와 perfect forwarding 에서 자세히 설명.
	int&& r3 = n;	// error
	int&& r4 = 3;	// ok
}