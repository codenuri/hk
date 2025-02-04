#include <iostream>
#include <vector>

class People
{
	std::string name;
	int age;
public:
	People(const std::string& name, int age) : name{name}, age{age} {}
};

// 아래 주석 해보세요
// 1. People 로 부터 파생된 Student 만드세요
// 2. int id 추가하세요
// 3. Student 생성자 만들어서 id 초기화 하세요
// 4. main 에서 Student 객체 생성해 보세요 

class Student : public People 
{
	int id;
public:
	// 아래 처럼만들면 컴파일러가 추가한 아래 주석때문에 에러 입니다.
	/*
	Student(int id) : id{id}   
	{
		// call People::People() 	=> error. People 에는 디폴트 생성자 없습니다다
	}
	*/
	// 아래 처럼해야 합니다.
	// => 많은 개발자가 "디폴트 생성자가 없는 클래스" 에서 상속받는 것을 어려워 합니다.
	// => 꼭 이해해 두세요
	Student(const std::string& name, int age, int id) : People{name, age}, id{id}{}
};

int main()
{
	Student s{"kim", 20, 15};
	
//	People p;	// 이렇게 객체를 만들수 있게 하면 좋을까요 ?
				// 이름과 나이가 초기화 되지 않은 쓰레기값을 가지는 객체
}



