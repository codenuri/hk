#include <iostream>

// 예외 문법
// => 함수가 실패하면 "예외라는 것을 던집니다(throw)"
// => 호출자가 던져진 예외를 잡지(catch) 않으면 프로그램은 비정상 종료 됩니다
// => 즉, 오류에 대한 처리를 반드시 해야 한다고 강제 하는 것!!
int db_backup()
{
	if (1)	// 실패라고 가정
		throw 1;

	return 100;
}
void db_remove() { std::cout << "db_remove\n"; }

int main()
{
	int ret = db_backup();
//	if (ret == -1) {} 
	db_remove();
}
