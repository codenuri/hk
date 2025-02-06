#include <iostream>

class vector 
{
	int* ptr;
	std::size_t sz;
public:
	vector(std::size_t size) : sz{size}
	{
		std::cout << "ctor\n";

		ptr = new int[sz];
	}
	~vector() { delete[] ptr; }
	

	vector(const vector& other) : sz{ other.sz} 
	{
		std::cout << "copy ctor\n";

		ptr = new int[sz];
		memcpy(ptr, other.ptr, sizeof(int)*sz);
	}
	
	vector(vector&& other) : sz{ other.sz}, ptr{other.ptr}
	{
		std::cout << "move ctor\n";
		other.ptr = nullptr; 
	}
	
};

int main()
{
	// 아래 한줄을 완벽히 이해해 봅시다.
	vector v = vector(10);

	// C++98
	// 1. 우변에 임시객체 생성 - 인자가 한개인 생성자 호출
	// 2. 임시객체를 복사생성자를 통해서 v에 복사
	
	// => 그런데, 대부분의 컴파일러는 copy ellision 최적화를 통해서 
	//    임시객체를 제거합니다.
	// 확인방법
	// #1. 복사생성자를 private 놓아 보세요 - 에러 발생
	// #2. -fno-elide-constructors 옵션 사용

	// g++ QA2.cpp -std=c++98
	//--------------------------------------
	// C++11
	// 1. 우변은 임시객체를 생성 - 생성자 호출
	// 2. 임시객체가 v에 들어갈때 이동생성자 호출.
	// => 역시 임시객체 제거되는 최적화 수행

	// g++ QA2.cpp -std=c++11 
	// g++ QA2.cpp -std=c++11 -fno-elide-constructors

	// C++17
	// 임시객체를 제거하는 최적화가, 최적화가 아닌 문법이 되었습니다.
	// => 따라서 "-fno-elide-constructors" 옵션이 주어도 
	// => 임시객체 제거가 최적화가 아닌 문법이므로 임시객체는 생성되지 않습니다.
	// => 이 한줄은 생성자만 호출됩니다.
	// 
}