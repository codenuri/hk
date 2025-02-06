#include <iostream>

class vector 
{
	int* ptr;
	std::size_t sz;
public:
	vector(std::size_t size) : sz{size}
	{
		ptr = new int[sz];
	}
	~vector() { delete[] ptr; }
	
	vector(const vector& other) : sz{ other.sz} 
	{
		ptr = new int[sz];
		memcpy(ptr, other.ptr, sizeof(int)*sz);
	}
	vector(vector&& other) : sz{ other.sz}, ptr{other.ptr}
	{
		other.ptr = nullptr; 
	}
};










int main()
{
	vector v1{10};

	vector v2 = v1; 		// v1 은 lvalue(이름있음). 복사생성자 호출

	vector v3 = vector{10};	// 우변은 rvalue(임시객체), 
							// 복사 생성자, 이동생성자 모두 가능하지만
							// 이동생성자(&&버전)이 우선적으로 선택됩니다.

	vector v4 = static_cast<vector&&>(v2); // v2자체는 lvalue 지만
											// rvalue reference 로 캐스팅했으므로
											// 이동생성자 호출
											// 즉, v2의 자원을 v4에 전달한것

	vector v5 = std::move(v3);	// 이 C++ 표준함수가 하는일이 
								// 위처럼 캐스팅 하는 일!!

	// 핵심
	// => std::move 가 자원을 이동하는거 아닙니다.!!!!
	// => std::move 는 rvalue로 캐스팅만 하고
	// => 캐스팅의 결과로 vector 의 이동생성자가 호출된것
	// => 즉, 이동 자체는 vector 설계자가 만든것
}