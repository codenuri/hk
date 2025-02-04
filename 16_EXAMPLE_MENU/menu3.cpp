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

	void command() 
	{
		while(true)
		{
			system("cls"); 

			auto sz = v.size();

			for( int i = 0; i < sz; i++)
			{
				std::cout << i + 1 << ". " << v[i]->get_title() << std::endl;
			}

			std::cout << sz + 1 << ". 종료\n";  

			std::cout << "메뉴 선택하세요 >> ";

			int cmd;
			std::cin >> cmd;

			if ( cmd < 1 && cmd > sz + 1 ) 
				continue;

			if ( cmd == sz + 1 )
				break;


			v[cmd-1]->command();
		}





	}
};


int main()
{
	MenuItem m1("참치  김밥", 11);
	MenuItem m2("돈까스 김밥", 12);

	PopupMenu kimbab("김밥류");
	kimbab.add(&m1);
	kimbab.add(&m2);
	//--------------------------
	MenuItem m9("라면", 21);

	PopupMenu pm("오늘의 점심메뉴");

	pm.add(&kimbab);// error. PopupMenu 의 add 는 MenuItem* 만 가능하다.
					// 해결책은 다음소스..
					
	pm.add(&m9);	// ok

	pm.command();  
}
