#include <iostream>

// 예외를 던질때, 최대한 자세한 정보를 알려 주어야 합니다
// => primitive 타입이 아니라 user define type 으로 설계 하세요

class file_not_found 
{
	// 다양한 멤버를 통해서 오류에 대한 정보 전달
};

// 아래 처럼 empty 로 해도 좋습니다.
// => 클래스 이름 자체가 설명
class disconnect_wifi{};

int db_backup()
{
	if (1)	
	{	
		file_not_found e;
		throw e; 
	}
	if ( 2 )
	{
		throw disconnect_wifi{}; // 이렇게 해도 됩니다. 임시객체 형태로 전달
								// 위와 동일하다고 생각하세요
	}

	return 100;
}
void db_remove() { std::cout << "db_remove\n"; }

int main()
{
	try 
	{
		int ret = db_backup();
	}
	catch(const file_not_found& e)
	{
		std::cout << "예외발생\n";
		std::exit(-1);
	}
	catch(const disconnect_wifi& e)
	{
	}
	catch( ... ) // 위에서 잡히지 않은 모든 종류의 예외
	{
		// 
	}

	db_remove();
}
