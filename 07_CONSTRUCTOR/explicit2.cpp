#include <string>
#include <vector>
#include <memory>

void f1(std::string s) {} // const& 가 좋지만 간단하게 설명하기 위해
void f2(std::vector<int> v){}

int main()
{
	// 아래 코드는 되는게 좋은까요 ? 안되는게 좋을까요 ?
	f1("hello");
	f2(10);

	std::string s = "hello";
	std::vector<int> v = 10; 

	std::shared_ptr<int> sp1 = new int;
	std::shared_ptr<int> sp2( new int);
}