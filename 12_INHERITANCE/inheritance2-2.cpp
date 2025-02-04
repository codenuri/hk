#include <list>

// STL 에 list 가 있는데, 사용자가 stack 을 요구합니다.
// stack 을 만들어 봅시다.

// #1. adapter 패턴
// => 기존 클래스의 인터페이스(함수 이름)을 변경해서 
// => 사용자가 원하는 다른 클래스처럼 보이게 만드는 디자인 기술
// private 상속의 의도 : 
// => 기반 클래스로 부터 기능은 물려 받지만(파생 클래스 내부적으로 사용)
// => 인터페이스는 물려받지 않겠다.(기반클래스 함수를 외부 노출하지 않겠다)
/*
//template<typename T> class stack : public std::list<T>
template<typename T> class stack : private std::list<T>
{
public:
	void push(const T& a) { std::list<T>::push_back(a);}
	void pop()            { std::list<T>::pop_back();}
	T&   top()            { return std::list<T>::back();}
};

int main()
{
	stack<int> s;
	s.push(10);
	s.push(20);
	s.pop();

	s.push_front(30); // 사용자가 이렇게 사용했다!!
}
*/

// #2. 상속이 아님 포함

// #1 과 #2 의 차이점
// private 상속 : std::list<T> 의 protected 멤버에 접근 가능하고
//				  std::list<T> 에 가상함수가 있다면 override 가능.

// 포함 : 위 기능을 할수 없다!!!

// 현재 코드는 "포함"이 좋다.
// => std::list 에 override 할 가상함수 없다.
/*
template<typename T> class stack
{
	std::list<T> c;
public:
	void push(const T& a) { c.push_back(a);}
	void pop()            { c.pop_back();}
	T&   top()            { return c.back();}
};

int main()
{
	stack<int> s;
	s.push(10);
	s.push(20);
	s.pop();

	s.push_front(30); // error. 이제 이 멤버 함수는 없다.
}
*/

// #3. policy base design
// => 클래스를 사용하는 어떤 정책을 "템플릿 인자" 로 교체하는 디자인 기술
#include <vector>
#include <deque>

template<typename T, typename C = std::deque<T> > class stack
{
	C c;
public:
	void push(const T& a) { c.push_back(a);}
	void pop()            { c.pop_back();}
	T&   top()            { return c.back();}
};
#include <stack> // 이 안에 있는 표준 stack 이 위와 같이 디자인 되었습니다.
				 //	그래서, "stack adapter" 라고 부릅니다.

int main()
{
	stack<int, std::list<int> > s;
	stack<int, std::vector<int> > s2;
	stack<int> s3;

	s.push(10);
	s.push(20);
	s.pop();
}

