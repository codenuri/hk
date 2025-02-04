class Shape
{
public:
	virtual void Draw() {};
	virtual void Move() {};
};
class Rect : public Shape
{
public:
	// #1. 가상함수를 override 할때는 virtual 은 있어도 되고 없어도 됩니다.
	// => virtual 을 붙이지 않아도 기반 클래스에서 virtual 로 선언되었기때문에 virtual 입니다.
//	virtual void Draw()  {}; // 이렇게 해도 되고
//	        void Draw()  {}; // 이렇게 해도 됩니다. 완전히 동일


	// #2. C++98 시절에 가상함수 재정의시 실수(오타)가 있어도
	// => 에러 아닙니다. 다른 함수라고 생각!!!
	// => 이 문제가 너무 많은 버그 유발.!!
//	virtual void draw() {};
//	virtual void Move(int n) {};


	//#3. 위문제의 해결책으로 C++11에서 override 키워드 도입.
	// => 새로운 함수가 아니라 override 한다고 알리는 것
	virtual void draw()      override {};	// error
	virtual void Move(int n) override {};	// error

};

int main()
{
	
}