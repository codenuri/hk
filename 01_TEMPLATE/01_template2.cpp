// 35 page

// 구현이 유사(동일)한 함수가 여러개 필요하면
// 함수를 만들지 말고, 함수의 틀을 만들자

template<typename T> 
T square(T a)
{
	return a * a;
}

int main()
{
	// #1. 함수 템플릿을 사용하는 정확한 표기법
	square<int>(3); 		// 1. 틀을 사용해서 int square(int) 함수 생성
							// 2. 이 위치는 call square(int) 로 변경
	square<double>(3.4);	// 1. 틀을 사용해서 double square(double) 함수 생성
							// 2. 이 위치는 call square(double) 로 변경

	// #2. 타입인자는 생략가능. 이경우 함수 인자로 타입을 추론
	square(3);	// 3을 보고 컴파일러가 T=int 로 추론
	square(3.3);
}

// template 을 정확히 이해하려면
// godbolt.org 같은 사이트에서 "어셈블리 코드를 보세요"


// 코드 폭발(Code bloat)
// => 템플릿 사용시 컴파일러가 너무나 많은 함수/클래스를 만들어서
//    코드 메모리가 증가하는 현상!!

// 임베디드 환경에서는 주의!!