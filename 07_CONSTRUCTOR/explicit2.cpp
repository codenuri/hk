#include <string>
#include <vector>
#include <memory>

void f1(std::string s) {} // const& 가 좋지만 간단하게 설명하기 위해
void f2(std::vector<int> v){}

int main()
{
	// 아래 코드는 되는게 좋은까요 ? 안되는게 좋을까요 ?
	f1("hello");	// ok
	f2(10);			// error

	std::string s = "hello";	// ok
								// std::string(const char*) 생성자는 explicit 아님.
	std::vector<int> v1(10);  // ok
	std::vector<int> v2 = 10;  // error. vector(int) 생성자는 explicit 라는 의미미

	std::shared_ptr<int> sp1 = new int; // error
	std::shared_ptr<int> sp2( new int); // ok.
}