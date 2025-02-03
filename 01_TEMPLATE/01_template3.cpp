// 다양한 함수 템플릿 모양

// #1.typename 대신 class 키워드 사용가능. 완전히 동일
// template<typename T> 
template<class T> 
T square(T a) 
{ 
	return a * a;
}


// #2. C++20 부터 auto 사용가능.
auto square(auto a) 
{ 
	return a * a;
}

// #3. C++20 부터 constraint(제약) 사용가능
// std::integral : C++20 concept 기술 - 5일차 소개.. 

// 아래 코드는 정수인 경우만 사용하겠다는 의미
//template<typename T>  	// 모든 타입을 받을수 있다.
template<std::integral T>   // 정수 계열 타입만 받겠다.
T square(T a) 				// 실수 계열에 대해서 이템플릿 사용하면 에러러
{ 
	return a * a;
}

// 위와 동일. 
auto square(std::integral auto a) 
{ 
	return a * a;
}