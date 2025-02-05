#include <iostream>
#include <exception>

// C++ 권장 : 예외 클래스 만들려면 std::exception 이라는 클래스에서 상속 받아라
class file_not_found : public std::exception
{
public:
	const char* what() const noexcept override 
	{
		// 왜 실패했는지 문자열로 반환해 주세요
		return "file not found\n";
	}
};


int db_backup()
{
	if (1)	
	{	
		file_not_found e;
		throw e; 
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

	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
		
		// RTTI : Runtime-type information
		const std::type_info& t = typeid(e); // e가 가리키는 객체의
												// 타입 정보를 알려달라

		std::cout << t.name() << std::endl;
				// ms 컴파일러 - 정확한 이름
				// g++ 컴파일러 - 변형된 이름
				// C++filt -t 변형된이름 => 실제 타입 이름


	}
	catch( ... ) // 위에서 잡히지 않은 모든 종류의 예외
	{
		// 
	}

	db_remove();
}
