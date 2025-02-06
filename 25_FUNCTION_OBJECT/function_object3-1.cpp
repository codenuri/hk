#include <iostream>
#include <bitset>

// 0 ~ 9 사이의 "중복 되지 않은 난수" 를 반환하는 함수
// => 일반 함수로 만들려면, 
// => 한번 반환값 난수값을 어딘가 보관했다가
// => 다음번에는 다른 난수로 반환해야 한다.
// => 어디에 보관할까 ??? 저장할 공간이 없다.. 전역변수로 해야 한다!!
int random()
{
	return rand() % 10;
}

int main()
{
	for( int i = 0; i <10; i++)
	{
		std::cout << random() << std::endl;
	}
}