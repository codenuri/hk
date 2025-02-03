// explicit.cpp

class vector
{
public:
	vector(int sz) {}
};

void foo(vector v) {}

int main()
{
	// 인자가 한개인 생성자가 있다면 아래 4가지 형태로 객체 생성가능합니다.
	vector v1(10);		// C++98 direct initialization
	vector v2 = 10;		// C++98 copy   initialization
	vector v3{1};		// C++11 direct initialization
	vector v4 = {1};	// C++11 copy   initialization


}