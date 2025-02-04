#include <vector>

// 135 page ~

class Animal
{
public:	
	int age;
};
class Dog : public Animal
{
public:	
	int color;
};
int main()
{
	Animal  a;

	Dog     dog;

	Dog*    p1 = &dog;	// ok

//	int*    p2 = &dog;	// error.
	

	// 핵심 #1. 기반 클래스 타입의 포인터에 
	//         파생 클래스 객체의 주소를 담을수 있다.
	// => upcasting 이라고 합니다.
	// => 원리는 메모리 그림을 그려 보세요
	Animal* p3 = &dog;	// ok

	// 핵심 #2. 컴파일 시간에는 p3가 가리키는 객체가
	// 정확히 어떤 타입의 객체인지 
	// 컴파일러는 알수 없다.
	// => 아래 처럼 실행시간에 변경될수 있으므로
//	if ( 사용자입력 == 1 ) p3 = &a;


	// 핵심 #3. Animal* 인 p3로는 Animal 의 멤버만
	//          접근가능하다.
	//			p3가 실제 Dog를 가리키더라도
	//			Dog 가 고유멤버는 접근 안됨
	// => C++은 컴파일 시간에 많은 것을 확인(static type check)
	// => 컴파일시간에는 p3가 가리키는 것이 Dog 라는 확신이없으므로 에러

	p3->age = 10;	// ok
	p3->color = 10; // error


	// 핵심 #4. p3를 가지고 Dog 고유 멤버에 접근하려면
	//		   Dog* 로 캐스팅해서 사용해야 한다.
	//		   가리키는 객체가 Dog 가 맞다고 개발자가 보증하는 과정

	Dog* pdog = static_cast<Dog*>(p3);

	pdog->color = 10;

	// 단 이때는 p3가 가리키는 곳이 Dog 라는 확신이 있어야 합니다.
	// => 아닌 경우 undefined!!

	// 조사할수없나요 ?
	// => dynamic_cast!  
}




