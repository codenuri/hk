// pointer vs reference
int main()
{
	int  n = 10;

	// #1. 초기화 하는 방법
	int* p1 = &n;
	int& r1 = n;

	// #2. 대상체(n) 에 접근
	*p1 = 20;
	r1  = 20;

	// #3. 
	int n2 = 20;

	p1 = &n2;
	r1 = n2;

	// #4.
	int* p2;
	int* p3 = nullptr;
	int& r2; 
}

// pointer 보다 reference 가 안전 하다.

void f1(int* p)
{
	*p = 10;
}

void f2(int& r)
{
	r = 10;
}