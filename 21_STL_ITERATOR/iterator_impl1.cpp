#include <iostream>

template<typename T>
struct Node 
{
	T data;
	Node* next;

	Node(const T& data, Node* next) : data(data), next(next) {}
};

template<typename T> 
class slist
{
	Node<T>* head = nullptr;
public:
	void push_front(const T& n) { head = new Node<T>(n, head);}
};





int main()
{
	slist<int> s;
	s.push_front(10);
	s.push_front(20);
	s.push_front(30); // 이때 메모리 그림을 생각해 보세요
}
// github.com/codenuri/STL_V2 ? (STLV2)  에서 section2 인가 보면 위 소스 있습니다
