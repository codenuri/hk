
// 인자를 수정하지 않고 읽기만 하려고 합니다.
// 다음중 좋은 것은 ?
void f1( BigData bd ) {}			// bad
void f2( const BigData& bd ) {}		// good


void f3(int n) 		  	// good
{
	int k = n;
}

void f4(const int& n)	// bad - 왜 ???
{
	int k = n; // 내부적으로 n은 포인터 이므로
				// int k = *(n이사용하는 포인터);
}

int main()
{
	int a = 0;
	f3(a);
	f4(a);
}

// 함수 인자 정리

// #1. 원본인자를 수정하려고 한다. 포인터 또는 reference 인데..
void inc(int* p) { ++(*p);}
void inc(int& r) { ++r;}		// 권장 : 간결하고, 안전하다.

// #2. 원본인자 수정 못하게 하고 싶다.
// 1. primitive 타입이나 크기가 작은 타입(Point 같은 구조체)
// => call by value
void foo(int n) {}

// 2. user define type 중, 크기가 크거나, 복사생성자가 있는 타입
// => const call by reference
void foo(const std::string& s) {}

// 구글에서 "C++ core guideline" 검색.