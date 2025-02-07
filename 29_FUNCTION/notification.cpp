// notification.cpp
#include <iostream>
#include <map>
#include <vector>
#include <functional>
#include <string>
using namespace std::placeholders;

class NotificationCenter
{
	using HANDLER = std::function<void()>;

	std::map<std::string, std::vector<HANDLER> > notif_map;

public:
	void add_observer(const std::string& key, HANDLER h)
	{
		notif_map[key].push_back(h);
	}
	void post_notification(const std::string& key)
	{
		for( auto f : notif_map[key] ) //  notif_map[key] 는 vector 입니다.
			f();
	}
};

void f1()       { std::cout << "f1\n";}
void f2(int id) { std::cout << "f2 :" << id << std::endl; }

struct Dialog 
{	
	void close(int code) {} 
};

int main()
{
	NotificationCenter nc;
	nc.add_observer("LOWBATTERY", &f1);
	nc.add_observer("LOWBATTERY", std::bind(&f2, 11));
	nc.add_observer("MOTOROFF",   std::bind(&f2, 12));

	Dialog dlg;
	nc.add_observer("LOWBATTERY", std::bind(&Dialog::close, &dlg, 0));

	nc.add_observer("LOWBATTERY", [](){ std::cout<< "lambda express\n";} );



	nc.post_notification("LOWBATTERY");
}