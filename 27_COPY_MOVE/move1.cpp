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
	
	// 임시객체가 아닌 경우의 복사 생성자
	vector(const vector& other) : sz{ other.sz} 
	{
		ptr = new int[sz];
		memcpy(ptr, other.ptr, sizeof(int)*sz);
	}
	
	// 임시객체인 경우의 복사 생성자 - "이동생성자(move constructor)" 라고 부릅니다.
	vector(vector&& other) : sz{ other.sz}, ptr{other.ptr}
	{
	//	ptr = other.ptr;

		other.ptr = nullptr; // 임시객체의 소멸자에서 delete 해도
							// 자원이 파되 되지 않게!
							// 이 작업을 하려면 "상수성 없이" 임시객체를 가리킬수
							// 있어야 합니다.

							// 즉, 파괴될 객체 라도 상태 변경이 가능하도록
							// "그래서 rvalue reference 는 상수성없이 임시객체를
							// 가리킬수있다" 가 필요!
	}

};










int main()
{
	vector v1{10};
	vector v2 = v1; 		// 우변은 lvalue 객체

	vector v3 = vector{10};	// 우변이 임시객체(rvalue) <= 이 코드가 핵심
}