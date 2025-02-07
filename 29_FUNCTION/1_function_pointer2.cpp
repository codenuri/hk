// C 포인터의 단점 #2

class Dialog 
{
public:
	void close(int code) {}	// void close(Dialog* this, int code)
	static void close2(int code) {} // static 은 "Dialog::close2(0)" 으로호출
								    // 즉 객체없이 호출가능.
};
void f1(int a) {}

int main()
{
	void(*f)(int);
	
	// 핵심 #1.
	// 1. 일반 함수 포인터에 "멤버함수의 주소" 를 담을수 없습니다.
	// 2. 일반 함수 포인터에 "static 멤버함수의 주소" 를 담을수 있습니다.
	// => this 추가 관점을 생각하면 됩니다.
	f = &f1;			// ok
//	f = &Dialog::close;	// error. close 는 멤버함수이므로 this 추가, 인자한개 아님
	f = &Dialog::close2; //ok. static 멤버 함수는 this 추가 안됨.


	// 핵심 #2. 멤버 함수의주소를 담는 멤버 함수 포인터 변수 만들기

	void(*f2)(int) = &f1;				// 일반 함수 포인터
	void(Dialog::*f3)(int) = &Dialog::close;	// 멤버 함수 포인터

	f2(0); // 일반 함수 포인터는 이렇게 호출(사용) 합니다.
//	f3(0); // 멤버 함수 포인터도 될까요 ? error. 객체(this)가 없습니다.
			// 멤버 함수는 "객체.함수()" 처럼 객체가 필요합니다.

	// #3. 멤버 함수 포인터 사용법
	Dialog dlg;
//	dlg.f3(0); // error. Dialog 안에 f3 이라는 이름은 없습니다.

	// 이때 사용하는 것이 pointer to member 라는 연산자 입니다.
	// .* 라는 C에는 없는 C++ 전용 연산자
//	dlg.*f3(0);	// error. 연산자 우선순위 문제, .* 보다 ( 가 빠르다.

	(dlg.*f3)(0); // ok. 이 표기법이 멤버 함수 포인터로 멤버 함수를 호출하는표기법 

	// #4. std::invoke
	f2(0); 			// 일반 함수 포인터로 함수 호출
	(dlg.*f3)(0); 	// 멤버 함수 포인터로 함수 호출

	// 위 2개의 코드를 동일하게 사용하게 하자...!! 라고 C++ 창시자가 아래문법제안
//	f3(&dlg, 0); // "uniform call syntax" 로 제안했으나 채택 안됨. 

	// 대신 C++17 에서 std::invoke 탄생
	std::invoke(f2, 0);       // f2(0) 해달라   즉, 일반함수 포인터 사용 
	std::invoke(f3, &dlg, 0); // (dlg.*f3)(0)      멤버 함수 포인터 사용
}
#include <functional>