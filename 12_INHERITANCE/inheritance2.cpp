// 상속에서는 "접근지정자" 가 한개 추가됩니다.

class Base
{
private:   	// 멤버 함수에서만 접근 가능
	int a;	

protected: 	// 멤버 함수와 파생 클래스의 멤버 에서 접근 가능
	int b;	

public:    	// 모든 함수에서 접근 가능
	int c;	

	void set_a(int v) { a = v;}
};

class Derived : public Base  
{
public:
	void foo()
	{
		a = 0;	// error. 기반 클래스 private
		b = 0;  // ok     기반 클래스 protected
		c = 0;  // ok.    public
	}
};
int main()
{
	Base base;
	base.a = 0; 	// error  private
	base.b = 0; 	// error  protected
	base.c = 0; 	// ok     public
}
