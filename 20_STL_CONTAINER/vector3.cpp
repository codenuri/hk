#include <iostream>
#include <vector>

int main()
{
	std::vector<int> v(5); // 5개를 0으로

	v.resize(3); // 어떻게 만들었을까요 ?
				 // 메모리를 줄이지 않고 size 멤버 변수만 3으로

	std::cout << v.size() << ", " << v.capacity() << std::endl; // 3, 5

	v.push_back(0); // 끝에 한개 추가	
					// 현재 size < capacity 이므로 메모리 재할당 필요 없다
					// not expensive operation

	std::cout << v.size() << ", " << v.capacity() << std::endl; // 4, 5							

	v.shink_to_fit(); // 필요없는 여분의 메모리 제거해 달라.
					  // => 새롭게 4개 메모리 확보해서 사용하는 것

	std::cout << v.size() << ", " << v.capacity() << std::endl; // 4, 4

	v.push_back(0); // size == capacity 이므로 메모리 재할당 필요
					// expensive operation
					// vector 는 메모리가 부족해지면 재할당할때
					// g++ : 기존 메모리 크기(capacity) 의 2배
					// visual studio : 1.5배

	std::cout << v.size() << ", " << v.capacity() << std::endl; // 5, 8

	v.clear();					

	std::cout << v.size() << ", " << v.capacity() << std::endl; // 0, 8

	v.shink_to_fit();

	std::cout << v.size() << ", " << v.capacity() << std::endl; // 0, 0
}
