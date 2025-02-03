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
// 아래 코드는 정수인 경우만 사용하겠다는 의미
template<std::integral T>  
T square(T a) 
{ 
	return a * a;
}

auto square(std::integral auto a) 
{ 
	return a * a;
}