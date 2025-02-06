#include <iostream>

// rvalue 와 rvalue reference
void foo(int&)  { std::cout << "int&\n";}
void foo(int&&) { std::cout << "int&&\n";}

int main()
{
	int&& r = 10;

	// 아래 코드가 각각 어떤 함수를 호출할지 생각해 보세요
	foo(10); // int&&
	foo(r);  // int&   => 핵심

	// value category : 어떤 값이 메모리를 가지고 있고,이름이 있는가 ?(lvalue)
	//					임시로 만들어진 이름이 없는 값인가?(rvalue)

	// 타입과 value categroy 를 구분하세요
	int n = 0;
	int& r1 = n;
	int&& r2 = 10;
	//					type			category
	// 10				int				rvalue
	// n				int				lvalue
	// pt				Point			lvalue
	// Point{1,1}		Point			rvalue
	// r1				int&			lvalue
	// r2				int&&			lvalue
	// -------------------------------------

	// foo(int&)  : int& 타입을 받겠다는게 아니라 lvalue 를 받겠다는것
	// foo(int&&) : int&& 타입을 받겠다는게 아니라 rvalue 를 받겠다는것

	foo(r2); // int&
	foo(static_cast<int&&>(r2)); // int&&
					// 이 캐스팅은 rvalue reference 로 캐스팅할까요 ?
					// rvalue 로 캐스팅 할까요 ? => 정답

					// !! r2 가 int&& 타입인데, 같은 타입인int&& 로
					// 캐스팅하는거 아닌가요 ??

					// C++ 표준문서에 static_cast<Type&&> 의 경우는
					// => 타입캐스팅이 아닌 value 캐스팅이다.
					//    라고 명시했습니다.
					
}