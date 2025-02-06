       int Add1(int a, int b) { return a + b; }
inline int Add2(int a, int b) { return a + b; }

int main()
{
	int n1 = Add1(1, 2); // 1. 인자2개를 약속된 장소(스택또는 레지스터)에 넣고
						 // 2. Add1 으로 이동 ( call Add1 )

	int n2 = Add2(1, 2); // Add2 의 기계어 코드를 이 위치에 치환
						 // 장점 : 빠르다는 것!

	int(*f)(int, int) = &Add2;

//	if ( 입력값 == 1 ) f = &Add1;

	f(1, 2); // 치환 ?  호출 ? => 호출!!
}
// 1. 인라인 치환은 컴파일 시간 문법입니다.
// 2. 인라인 함수라도 함수 포인터에 담아서 사용하면 인라인 치환될수 없습니다.
//   => 빨라 질수 없습니다.