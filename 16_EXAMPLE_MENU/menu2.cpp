#include <iostream>
#include <string>
#include <vector>
#include <conio.h>

class MenuItem
{
	std::string title;
	int         id;
public:
	MenuItem(const std::string& title, int id) : title{title}, id{id} {}

	std::string get_title() const { return title;}

	void command() 
	{
		std::cout << get_title() << " 메뉴 선택됨\n";
		_getch();
	}
};

class PopupMenu 
{
	std::string title;
	std::vector<MenuItem*> v;
public:
	PopupMenu(const std::string& title) : title{title}{}

	void add(MenuItem* m) { v.push_back(m);}

	// popupmenu 를 선택할때 호출되는 함수
	void command() 
	{
		while(true)
		{
			system("cls"); // 화면 지우기

			auto sz = v.size();

			for( int i = 0; i < sz; i++)
			{
				std::cout << i + 1 << ". " << v[i]->get_title() << std::endl;
			}

			std::cout << sz + 1 << ". 종료\n";   // 3. 종료

			std::cout << "메뉴 선택하세요 >> ";

			int cmd;
			std::cin >> cmd;

			if ( cmd < 1 && cmd > sz + 1 ) // 잘못된 입력
				continue;

			if ( cmd == sz + 1 )
				break;


			// 선택된 메뉴 실행
			v[cmd-1]->command();
		}





	}
};


int main()
{
	MenuItem m1("김밥", 11);
	MenuItem m2("라면", 12);

	PopupMenu pm("오늘의 점심메뉴");

	pm.add(&m1);
	pm.add(&m2);

	pm.command();  // 팝업메뉴를 선택할때를 생각해 보세요
}
