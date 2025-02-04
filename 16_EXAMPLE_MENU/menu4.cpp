#include <iostream>
#include <string>
#include <vector>
#include <conio.h>

// C 언어 : 메모리 구조를 이해하기 위해 메모리 그림을 그리면서 학습합니다.
// 객체지향 : 디자인을 이해하기 위해서는 "클래스 다이어그램(구조도)"를 그리세요


class BaseMenu
{
	std::string title;
public:
	BaseMenu(const std::string& title) 
		: title{title}{}

	virtual ~BaseMenu() {}

	std::string get_title() const { return title;}


	virtual void command()  = 0;
};



class MenuItem : public BaseMenu
{
	int         id;
public:
	MenuItem(const std::string& title, int id) 
		: BaseMenu{title}, id{id} {}


	void command() 
	{
		std::cout << get_title() << " 메뉴 선택됨\n";
		_getch();
	}
};

class PopupMenu : public BaseMenu
{
	std::vector<BaseMenu*> v;
public:
	PopupMenu(const std::string& title) : BaseMenu{title}{}

	void add(BaseMenu* m) { v.push_back(m);}


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

	pm.add(&kimbab);
					
	pm.add(&m9);	

	pm.command();  
}
