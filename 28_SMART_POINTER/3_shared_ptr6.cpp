#include <iostream>
#include <memory>

struct People
{
	std::string name;

	People(const std::string& n) : name{n} {}
	~People() { std::cout << name << " 파괴" << std::endl; }

	// 해결책 #2. std::weak_ptr

	//std::shared_ptr<People> bf; 	// 참조계수 증가, 상호참조 문제 발생생

	// People* bf;	// raw pointer 이므로 참조계수 증가 안함
					// 객체 파괴 조사 못함. dangling pointer 발생 가능

	std::weak_ptr<People> bf;		// 참조계수 증가안하는 스마트 포인터
									// 객체 파괴 조사 가능.
};

int main()
{
	std::shared_ptr<People> sp1{new People{"kim"}};
	{
		std::shared_ptr<People> sp2{new People{"lee"}};

		sp1->bf = sp2;
		sp2->bf = sp1;

	} // <= lee 파괴

	if ( sp1->bf.expired() )
	{
		std::cout << "가리키던 객체 파괴됨\n";
	}
	else 
	{
		// 파괴 되지 않은 경우
		// 이름을 얻고 싶다.
//		auto sp1->bf->name; // error. std::weak_ptr 로는 대상체 접근 안됨
							// -> 연산자 제공 안함.

		// weak 는 참조계수를 증가하지 않으므로 객체 접근 권한이 없습니다.
		// 접근하려면 참조계수를 늘려야 하고
		// 참조계수를 늘리는 방법은 shared_ptr 을 만들어야 합니다.
		
		// weak_ptr 이 가리키는 객체에 대한 shared_ptr 만들기
		std::shared_ptr<People> sp = sp1->bf.lock();

		if ( sp != nullptr )
		{
			auto name = sp->name;	
		}


	}
}


