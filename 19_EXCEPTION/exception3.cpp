#include <iostream>

// throw : 예외를 던질때 사용
// try~catch : 예외를 잡을 때 사용

int db_backup()
{
	if (1)	
		throw 1;

	return 100;
}
void db_remove() { std::cout << "db_remove\n"; }

int main()
{
	try 
	{
		int ret = db_backup();
	}
	catch(int e)
	{
		// 이 안에서 발생된 오류를 확인하고, 해결할수 있다면 해결 합니다.
		// 해결할수 없다면 사용자에게 알리고 종료 시키세요
		std::cout << "예외발생\n";
		std::exit(-1);

		// 종료하지 않으면 프로그램을 계속 실행됩니다.
	}

	db_remove();
}
