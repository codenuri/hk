// 4_접근지정자1 - 74page
#include <iostream>
#include <string>

// struct vs class

// struct : 접근지정자를 표기하지 않으면 public 이 디폴트
// class  : 접근지정자를 표기하지 않으면 private 이 디폴트

// C++ 에서는 위 차이점만 있습니다.
// Java, C# 은 아주 큰 차이가 있습니다.
// Rust 는 struct 만 있습니다.

//struct Person
class Person
{
//private:				
	std::string name;
	int  age;	

public:
	void set_age(int a)
	{
		if ( a >= 0 && a < 150)
			age = a;
	}
};

int main()
{
	Person p;
	p.name = "kim";
	
	p.set_age(-10); 
}
