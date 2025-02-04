class Base 
{
	int base_data;
public:
	void foo() {}
};
// 접근 변경자 : 기반 클래스의 접근지정자 권한을 축소 할때 사용용
//class Derived : private Base // 기반 클래스 모든 멤버를 Derived의 private으로 상속속
//class Derived : protected Base   // 기반 클래스 public멤버를 => protected 로상속속
class Derived : public Base  // 기반 클래스의 접근 권한을 변경하지 않는것것
{

};

int main()
{
	Base b;
	b.foo(); // ok public
	Derived d;
	d.foo(); //  private 상속이면 private 멤버 이므로 error.
}