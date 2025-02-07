#include <memory>
#include <iostream>

int main()
{
	// unique_ptr 정리

	// 1. make_unique 로 사용하세요
	std::unique_ptr<int> up1{new int};	//
	std::unique_ptr<int> up2 = std::make_unique<int>(); // ?
	
	auto up3 = std::make_unique<int>();

	std::cout << sizeof(up1) << std::endl; // sizeof(raw pointer) 와동일
											// 오버헤드 없습니다.




	// 2. 자원을 독점합니다.
	// => 하나의 객체는 하나의 스마트 포인터만 사용가능
	std::unique_ptr<int> up4 = up1;				// error
	std::unique_ptr<int> up5 = std::move(up1);	// ok


	// 3. 아주 가볍습니다.(raw pointer 와 거의 동일한 성능)
	std::cout << sizeof(up1)  << std::endl;
	std::cout << sizeof(int*) << std::endl;


	// C++ 표준 스마트 포인터는 3개 입니다.
	// 
	// #1. 한개의 객체를 한개의 스마트 포인터로만 관리하고, 자동삭제 기능만 필요 하면
	// => 소유권 독점
	// => std::unique_ptr 사용하세요

	// #2. 한개의 객체를 여러개의 스마트 포인터. 자원의 공유
	// => 소유권 공유
	// => std::shared_ptr

	// #3. 자원에 대한 소유권이 없는 스마트 포인터
	// => 소유권 없음.
	// => std::weak_ptr
	// => 상호 참조 발생 가능성이 있을때 사용. 
}
// 편리하기 위해 스마트 포인터를 사용하는것이 아니라!!
// 안전하기 위해 (dangling pointer 방지) 사용하는것 입니다.