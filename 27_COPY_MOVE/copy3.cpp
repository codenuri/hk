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

	// deep copy 로 구현한 복사 생성자
	vector(const vector& v) : sz(v.sz)
	{
		// 포인터가 아닌 멤버는 그냥 복사
	//	sz = v.sz;

		// 포인터는 메모리 자체를 복사
		ptr = new int[sz];
		memcpy(ptr, v.ptr, sizeof(int)*sz);
	}
};

int main()
{
	vector v1{10};

	vector v2 = v1; 
	
}