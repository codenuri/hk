#include <iostream>

// 용어 정리

// 강한 결합(tightly coupling)
// => 하나의 클래스가 다른 클래스 사용시 "클래스 이름"을 직접 사용하는것
// => People::use_camera(Camera*)
// => 교체불가능한 확장성 없는 경직된 디자인


// 약한 결합(loosely coupling)
// => 하나의 클래스가 다른 클래스 사용시 "규칙을 담은 추상클래스(인터페이스)"을 
//		통해서  사용하는것
// => People::use_camera(ICamera*)
// => 교체가능한 확장성 있는 유연한 디자인

//------------------------------------------------------------
// C++ 문법 : 컨테이너에 참조 타입 보관 못함
//            std::vector<int*> : ok
//            std::vector<int&> : error
// 포인터 : 대상체 변경 가능
// 레퍼런스 : 대상체 변경 안됨.
//------------------------------------------------

// 인터페이스와 추상 클래스 용어가 혼란스럽게 섞여서 사용됩니다.
// 아래와 같이 구별하세요

// 인터페이스 : 지켜야 하는 규칙만 담고 있는 경우
// 추상클래스 : 지켜야 하는 규칙만 담고 있는 경우 + 다른 멤버

// C#, Java : abstract, inteface 라는 키워드가 있어서 명확
// C++ : 키워드 없음, 단지 위 처럼 구분하는 경우가 많음



// 카메라와 사람을 먼저 설계하지 말고

// 모든 카메라가 지켜야 하는 규칙을 먼저 설계한다.
// 규칙 : "모든 카메라는 아래 클래스로 부터 파생되어야 한다." 라고 표현하지 말고
//        "모든 카메라는 아래 인터페이스를 구현해야 한다." 라고 표현합니다.

#define interface struct 
//class ICamera 
struct ICamera 
//interface ICamera 
{
	virtual void take() = 0;
	virtual ~ICamera() {} // 인터페이스는 결국 기반 클래스이므로
						  // 소멸자를 가상함수로	
};



// 규칙이 있으므로 실제 카메라가 없어도 사용하는 코드를 만들수 있다.
// => 규칙 대로 사용
class People 
{
public:
	void use_camera(ICamera* c) { c->take();}
};

// 이제 모든 카메라 제조사는 반드시 "규칙대로 설계" 해야 한다.
class Camera : public ICamera
{
public:
	void take() { std::cout << "take picture" << std::endl; }
};

class HDCamera: public ICamera
{
public:
	void take() { std::cout << "take HD picture" << std::endl; }
};

class UHDCamera: public ICamera
{
public:
	void take() { std::cout << "take UHD picture" << std::endl; }
};

int main()
{
	People p;

	Camera c;
	p.use_camera(&c);	

	HDCamera hc;
	p.use_camera(&hc); 

	UHDCamera uhc;
	p.use_camera(&uhc);
}
