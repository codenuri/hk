#include <iostream>
#include <string>
#include <vector>
#include <memory>

class BaseMenu
{
	std::string title;
public:
	BaseMenu(const std::string& title) : title{title} {}
	virtual ~BaseMenu() {}
	
	std::string get_title() const { return title; }
	virtual void command() = 0;
};


class PopupMenu : public BaseMenu
{
	std::vector< std::shared_ptr<BaseMenu> > v;  
public:
	PopupMenu(const std::string& title) : BaseMenu{title} {}

	void add(const std::shared_ptr<BaseMenu>& m) { v.push_back(m); }

	void command()
	{
		while (1)
		{
		//	system("clear"); // linux
		//  system("cls")	 // windows

			auto sz = v.size();

			for (int i = 0; i < sz; i++)
			{
				std::cout << i + 1 << ". " << v[i]->get_title() << std::endl;
			}
			std::cout << sz + 1 << ". 종료\n";

			std::cout << "메뉴를 선택하세요 >> ";

			int cmd;
			std::cin >> cmd;

			if (cmd == sz + 1)
				break;

			if (cmd < 1 || cmd > sz + 1)
				continue;

			v[cmd - 1]->command();	
		}
	}
};

class MenuItem : public BaseMenu
{
	int id;
public:
	MenuItem(const std::string& title, int id) : BaseMenu{title}, id{id} {}

	void command()
	{
		std::cout << get_title() << " 메뉴가 선택됨\n";
	}
};

int main()
{
	std::shared_ptr<PopupMenu> root = std::make_shared<PopupMenu>("root");
	std::shared_ptr<PopupMenu> pm1 = std::make_shared<PopupMenu>("색상 변경");
	std::shared_ptr<PopupMenu> pm2 = std::make_shared<PopupMenu>("해상도 변경");

	root->add(pm1);
	root->add(pm2); 

	pm1->add(std::make_shared<MenuItem>("RED",   11));
	pm1->add(std::make_shared<MenuItem>("GREEN", 12));
	pm1->add(std::make_shared<MenuItem>("BLUE",  13));

	pm2->add(std::make_shared<MenuItem>("HD",  21));
	pm2->add(std::make_shared<MenuItem>("FHD", 22));
	pm2->add(std::make_shared<MenuItem>("UHD", 23));

	root->command();
}



