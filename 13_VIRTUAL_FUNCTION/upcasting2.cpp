// 6_Upcasting1.cpp      140 page ~
#include <vector>

class Animal
{
public:	int age;
};
class Dog : public Animal
{
public:	int color;
};
class Cat : public Animal
{
public:	int speed;
};

int main()
{
	// Upcasting 활용/장점
	std::vector<Dog*>    v1; // Dog 객체만 보관 가능한 컨테이너
	std::vector<Animal*> v2; // 모든 동물을 보관하는 컨테이너
							// 동종(동일 기반 클래스 사용하는 타입)을 보관하는 컨테이너

}