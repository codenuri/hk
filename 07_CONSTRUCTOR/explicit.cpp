// explicit.cpp

class vector
{
public:
//	vector(int sz) {}

	// explicit 생성자 : 복사초기화는 사용할수 없고, 직접 초기화만 가능하다
	//	이제 아래 main 에서 "copy" 가 있는 모든 초기화는 에러.
	explicit vector(int sz) {}
};

void foo(vector v) {}

int main()
{
	// 인자가 한개인 생성자가 있다면 아래 4가지 형태로 객체 생성가능합니다.
	vector v1(10);		// C++98 direct initialization
	vector v2 = 10;		// C++98 copy   initialization
	vector v3{10};		// C++11 direct initialization
	vector v4 = {10};	// C++11 copy   initialization

	// 아래 코드를 생각해 보세요
	foo(10);	// 함수의 인자 전달은 "복사 초기화" 과정입니다.
				// vector v = 10

}