// C 포인터의 단점 #1

void f1(int a) {}
void f2(int a, int b) {}

int main()
{
	// #1. 포인터 만드는법
	// => 변수(함수) 선언문에서 이름 앞에 * 만 붙이면 됩니다.
	// => 단, 연산자 우선 순위 문제가 있을때는 () 필요

	int *n;
	double *d;

//	void *fp(int a);	// fp 라는 이름 앞 뒤로 연산자가 있는데
						// * 보다 ( 가 우선순위가 높아서
						// 포인터가 아닌 함수로 해석

	void (*fp)(int); // fp 를 함수선언이 아닌 포인터로 하기 위해
					// * 연산자의 우선순위를 높여야 합니다
					// 그래서 () 필요


	int x[3] = {1,2,3};

	// 배열 x의 주소를 담는 포인터 변수 p 만들어 보세요
//	int* p = x; // 절대 배열 x의 주소 아닙니다

	// 규칙 1. 변수의 주소를 구하려면 "&변수이름"
	// 규칙 2. 포인터 변수를 만들려면 선언문에서 변수이름앞에 *
	// => 단, 이름 앞뒤에 연산자가 있으면 () 를 사용해서 우선순위 증가!
	int (*p)[3] = &x; // 이 코드가 배열의 주소를 담는 
					  // 포인터 변수 p 입니다.
}

