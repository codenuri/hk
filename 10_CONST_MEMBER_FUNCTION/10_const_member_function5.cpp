#include <string>

class Point 
{
	int x, y;
public:
	Point(int a, int b) : x{a}, y{b} {}

	std::string to_string()
	{
		std::string s = std::to_string(x) + ", " + std::to_string(y);
	}
};

int main()
{
	Point p(1,2);
	std::cout << p.to_string() << std::endl;
}