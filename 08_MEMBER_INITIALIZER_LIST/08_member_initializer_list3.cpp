#include <string>

// std::string 은 alias 입니다. 
// 실제 이름은 std::basic_string 이라는 템플릿 입니다.


class Person1
{
	std::string name;
	int age;
public:
	Person1(const std::string& n, int a) 
	{
		// call std::string::string()  - name에 대해서 

		name = n; // name.operator=(n) 함수 호출	
				  // 즉, 이코드는 초기화가 아닌 대입입

		age = a;
	}
};

// Person1 p1("kim", 20);



class Person2
{
	std::string name;
	int age;
public:
	// 초기화 리스트의 의미
	// => 멤버 데이타의 생성자 호출하는 코드를 만들때
	// => 초기화 리스트 모양대로 만들어 달라는 것(디폴트 생성자가 아닌 다른 생성자)
	Person2(const std::string& n, int a) : name{n}, age{a}
	{
		// call std::string::string()  이렇게 만들지 않고!!
		// call std::string::string{n}  이렇게 만들게 된다. {}또는 () 동일
	}
};



int main()
{
	Person1 p1("kim", 29);	
	Person2 p2("kim", 29);
}