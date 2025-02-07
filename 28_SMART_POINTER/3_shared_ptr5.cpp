#include <iostream>
#include <memory>

struct People
{
	std::string name;

	People(const std::string& n) : name{n} {}
	~People() { std::cout << name << " 파괴" << std::endl; }

	// 해결책 #1. bf 멤버를 shared_ptr이 아니라 raw Pointer로
	//std::shared_ptr<People> bf; 

	People* bf;	// raw pointer 이므로 참조계수 증가 안함
};

int main()
{
	std::shared_ptr<People> sp1{new People{"kim"}};
	{
		std::shared_ptr<People> sp2{new People{"lee"}};

		sp1->bf = sp2.get();
		sp2->bf = sp1.get();

	} // <== 여기서 sp2가 파괴, lee 객체 파괴 되지만
	  // sp1->bf 가 0이 되는 것은 아닙니다.
	  // 그래서 아래 처럼 사용했다면 dangling pointer
	  // 즉, raw pointer 는 객체 파괴여부를 조사할수 없다.

	if ( sp1->bf != nullptr )
	{
		auto p = sp1->bf->name;
	}
}


