int main()
{
	const int c = 10;

	// c의 주소를 double* 에 담고 싶습니다.
//	double* p = (double*)&c; // C언어는 이렇게 하면 ok
 
//	double* p = ? &c; // C++로 해보세요


	double* p = static_cast<double*>(&c);		// error
	double* p = reinterpret_cast<double*>(&c);	// error. const 제거 못함
	double* p = const_cast<double*>(&c);		// error. 다름 타입이므로!!


	double* p = reinterpret_cast<double*>(const_cast<int*>(&c));
				// 1. const int* => int*
				// 2. int* => double*
}





