#include <iostream>
#include <string>
#include <vector>
#include <conio.h>

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
	PopupMenu* root = new PopupMenu("ROOT");
	PopupMenu* pm1 = new PopupMenu("해상도 변경");
	PopupMenu* pm2 = new PopupMenu("색상 변경");

	root->add(pm1);
//	root->add(pm2);
	pm1->add(pm2);

	pm1->add( new MenuItem("HD",11));
	pm1->add( new MenuItem("FHD",12));
	pm1->add( new MenuItem("UHD",13));
	pm1->add( new MenuItem("8K",14));

	pm2->add( new MenuItem("RED",  21));
	pm2->add( new MenuItem("GREEN",22));
	pm2->add( new MenuItem("BLUE", 23));

	// 이제 시작하려면 ??
	root->command();

}

// 객체지향 프로그래밍 관점에서 "프로그램" 이란 ?

// 1. 객체를 생성하고
// 2. 객체간의 관계를 설정하고
// 3. 객체간의 메세지를 주고 받는 과정이다.(객체가 서로의 멤버함수를 호출)

// 4. 프로그램의 기본 단위는 "함수"가 아니라 "클래스" 이다.!!

// 확장성이 좋고, 유지보수가 쉽다.

// 단점 : 어렵다!!