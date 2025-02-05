#include <iostream>

template<typename T>
struct Node 
{
	T data;
	Node* next;

	Node(const T& data, Node* next) : data(data), next(next) {}
};

// 싱글리스트 반복자 만들어 봅시다.(STL 원리입니다)
template<typename T>
class slist_iterator 
{
	Node<T>* current;
public:
	slist_iterator(Node<T>* p = nullptr) 
		: current(p) {}

	// 반복자를 포인터 처럼 사용하게 하려면 4개의 
	// 연산자 재정의 필요
	slist_iterator& operator++()
	{
		current = current->next;
		return *this;
	}
	//*p = 0;즉 p.operator*() = 0  이코드가 되려면
	// 함수 호출이 =의 왼쪽에가능해야 합니다 참조 반환
	T& operator*() 
	{
		return current->data;
	}

	bool operator==(const slist_iterator& p) const 
	{
		return current == p.current;
	}
	bool operator!=(const slist_iterator& p) const 
	{
		return current != p.current;
	}
};


template<typename T> 
class slist
{
	Node<T>* head = nullptr;
public:
	void push_front(const T& n) { head = new Node<T>(n, head);}

	// 모든 컨테이너는 자신의 반복자이름을 약속된 별명으로 외부에 노출합니다.
	using iterator = slist_iterator<T>;

//	slist_iterator<T> begin()
	iterator begin()
	{
		slist_iterator<T> it(head);
		return it;
	}

//	slist_iterator<T> end()
	iterator end()
	{
		slist_iterator<T> it(0);
		return it;
	}

};

int main()
{
	slist<int> s;
	s.push_front(10);
	s.push_front(20);
	s.push_front(30);

	auto p1 = s.begin();
//	auto p2 = s.end();
	slist<int>::iterator p2 = s.end();

	while( p1 != p2)
	{
		std::cout << *p1 << std::endl;
		++p1;
	}
}

