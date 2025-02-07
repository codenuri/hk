#include <iostream>

// 1. Car 뿐 아니라 다양한 타입에 대한 포인터로 사용 가능해야 합니다.
// => template!!

// 2. 얕은 복사 문제를 해결해야 합니다.
// => 참조계수(reference counting)로 해결

template<typename T>
class Ptr
{
	T* obj;
	int* ref;
public:
	Ptr(T* p = 0) : obj(p) 
	{
		ref = new int;
		*ref = 1;	
	}



	~Ptr() 
	{ 
		if ( --(*ref) == 0)
		{
			delete obj;
			delete ref;
		}
	}

	T* operator->() { return obj; }
	T& operator*() { return *obj; }

	// reference counting 으로 구현한 복사 생성자
	Ptr(const Ptr& other) 
		: obj(other.obj), ref(other.ref)
	{
		++(*ref);
	}
};

int main()
{
	Ptr<int> p1 = new int;
	*p1 = 10;

	Ptr<int> p2 = p1; 
}


