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
	std::shared_ptr<People> sp2{new People{"lee"}};


	sp1->bf = sp2.get();
	sp2->bf = sp1.get();


	// 이제 객체 안전하게 파괴 됩니다.
	// => 그런데.. 안전하지 않습니다
	// => 다음소스 참고
}


