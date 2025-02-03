// pointer vs reference

// 대부분의 컴파일러가 레퍼런스 구현을 내부적으로 포인터 사용합니다
// => 단, 컴파일러에 따라 다를수 있습니다.


// pointer vs reference 차이점.

int main()
{
	int  n = 10;

	// #1. 초기화 하는 방법, & 연산자에 대해서

	int* p1 = &n;	// 주소로 초기화, & 연산자는 "주소연산자"
	int& r1 = n;	// 변수이름으로 초가화, & 연산자는 "레퍼런스 연산자자"

	// #2. 대상체(n) 에 접근
	*p1 = 20;	// * 필요
	r1  = 20;	// * 필요 없음.

	// #3. 
	int n2 = 20;

	p1 = &n2;	// p1이 가리키는 대상체 변경. 
	r1 = n2;	// 대상체 변경 아님. n2값을 r1의 대상체에 대입
				// 레퍼런스는 n1 의 별명으로 만든후에는 변경할수 없다.

	// #4.
	int* p2;			// ok. 초기값없어도 된다.
	int* p3 = nullptr;	// ok. null pointer 도 가능

	int& r2; 	// error.반드시 초기화 필요
	int& r2 = nullptr; // error. 
	int& r2 = n2; // ok . 반드시 유효한 대상체 필요
}

// pointer 보다 reference 가 안전 하다.

void f1(int* p)
{
	if ( p != nullptr) // 안전하게 하려면 check 필요!!
		*p = 10;
}

void f2(int& r)
{
	r = 10;	// r은 항상 유효하다.!! check 필요 없다.
}
f1(nullptr); // ok
f2(nullptr); // error. 유효하지 않은 객체를 보낼수 없다.