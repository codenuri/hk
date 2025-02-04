// 152 page ~
// 추상 클래스 
// 정의 : 순수 가상 함수가 한개 이상 있는 클래스
// 특징 : 객체를 생성할수 없다.
// 의도 : 약속된 함수를 반드시 구현해야 한다고 지시하는 문법
class Shape
{
public:
	virtual void draw()  = 0; // 순수 가상함수(pure virtual function)	
							  // 구현부가 없고, =0 으로 표기
};
class Rect : public Shape
{
	// Shape 에서 상속받은 draw()의
	// 구현부를 제공하지 않으면 Rect 도 추상(abstract)
	// 구현부를 제공하면 추상 아님(구체, concrete)
public:
	void draw() override {}
};
int main()
{
	Shape s; // error
	Rect  r; // ok
}


