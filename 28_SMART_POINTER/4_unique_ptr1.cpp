#include <iostream>

// shared_ptr 이 복잡했던 이유는
// => 한개의 객체를 "2개 이상의 스마트 포인터로 공유" 했기 때문..!

template<typename T>
class Ptr
{
	T* obj;
public:
	Ptr(T* p = 0) : obj(p) {}
	T* operator->() { return obj; }
	T& operator*() { return *obj; }
	~Ptr() { delete obj; }

	// 함수 삭제 문법
	// => 컴파일러에게 복사생성자를 만들지 말라고 지시하는 것
	// => 복사가 필요한 모든 코드는 컴파일 에러!
	Ptr(const Ptr& other) = delete;
};

int main()
{
	Ptr<int> p1 = new int;

	Ptr<int> p2 = p1; // error. 복사생성자가 없다다
}


