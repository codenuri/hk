#include <iostream>

class Camera
{
public:
	void take() { std::cout << "take picture" << std::endl; }
};

class HDCamera
{
public:
	void take() { std::cout << "take HD picture" << std::endl; }
};


class People
{
public:
	void use_camera(Camera* c)   { c->take(); }
	void use_camera(HDCamera* c) { c->take(); }
};

int main()
{
	People p;

	Camera c;
	p.use_camera(&c);	

	HDCamera hc;
	p.use_camera(&hc); // ???
}

// 위 코드는 새로운 카메라가 추가되면
// => 기존의 People 클래스가 수정되어야 합니다.
// => OCP 위반 입니다!!
// => 나쁜 디자인