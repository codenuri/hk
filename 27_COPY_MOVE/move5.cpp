#include <string>
#include <vector>
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
	/*
	vector(vector&& other) : sz{ other.sz}, ptr{other.ptr}
	{
		other.ptr = nullptr; 
	}
	*/
};

int main()
{
	// std::move : 단지, 캐스팅만 하는 것

	int n1 = 10;
	int n2 = std::move(n1);	// 아무 효과 없음. 에러도 아니고, 성능저하도 없음.

	int* p1 = new int;
	int* p2 = std::move(p1); // 아무 효과 없음. int* p2 = p1 과 동일,

	vector v1{10};
	vector v2 = std::move(v1);	// 이동생성자가 없으므로 복사생성자 호출
								// 즉, 이코드는 
								// 이동생성자가 있으면 사용
								// 없으면 복사 생성자 사용

								// => 성능향상은 되지 않아도 문제될것은 없다.
								// 즉, 개발자는 어떤 타입이 이동을 지원하는지 몰라도
								// std::move 사용해도 된다.

	std::string s1 = "hello";
	std::string s2 = std::move(s1); // std::string 은 move 지원 클래스 이므로
									// 이동 효과가 있다.!!

}