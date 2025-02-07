#include <iostream>
#include <memory>

// 스마트 포인터를 사용하려면 반드시 이번 주제를 이해해야 합니다.

struct People
{
	std::string name;

	People(const std::string& n) : name{n} {}
	~People() { std::cout << name << " 파괴" << std::endl; }

	std::shared_ptr<People> bf; // best friend
};

int main()
{
	// 설명을 위해 std::make_shared 대신 직접 new
	std::shared_ptr<People> sp1{new People{"kim"}};
	std::shared_ptr<People> sp2{new People{"lee"}};

	// 스마트 포인터 사용시 자동 delete 되므로 사용자가 직접 delete 할필 없습니다.

	// 단, 아래 코드가 있으면 delete 안됩니다.
	sp1->bf = sp2;
	sp2->bf = sp1;

	// 핵심 : 스마트 포인터 사용시
	//		 상호 참조, 원형 참조가 발생하면
	//		메모리 삭제되지 않습니다.
	// 		해결책은 다음 소스...

	// 이예제 실행하면 소멸자 호출 안됩니다.
}


