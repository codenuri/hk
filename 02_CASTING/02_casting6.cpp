// const_cast : 상수성 제거를 위한 캐스팅
//			   => 동일 타입으로만 상수성 제거 가능.

int main()
{
	const int c = 10;

	int* p3 = static_cast<int*>(&c); // error
	int* p3 = reinterpret_cast<int*>(&c); // error
	int* p3 = const_cast<int*>(&c); // ok.

	*p3 = 20;	// 절대 이렇게는 사용하면 안됩니다. undefined
				// 그래서
				// const_cast 는 원본이 상수인 변수에 대해서는 
				// 절대 사용하면 안됩니다.
				// 위 캐스팅이 에러 아니지만 사용하지 마세요
				// 아래 경우만 사용하세요
	//-------------------------------------------------

	int n = 10;	// 원본은 상수가 아닌데

	const int* p = &n;	// 가리키는 포인터가 상수
						// 즉, p를 통해서는 읽기만 하겠다는 의도. 좋은 코드

	int* p1 = p;	// error. 아래 처럼 const_cast 만 가능.
	int* p2 = static_cast<int*>(p);		//error
	int* p2 = reinterpret_cast<int*>(p);//error  
	int* p2 = const_cast<int*>(p); // ok, 이런 경우에 사용하라고 만든 캐스팅

	*p2 = 20;

	
	
}
