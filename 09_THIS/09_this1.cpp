#include <iostream>

class Point
{
	int x, y;
public:
	void set(int a, int b)	
	{						
		x = a;				
		y = b;				
	}
};

int main()
{
	Point p1;
	Point p2;
	std::cout << "p1 : " << &p1 << std::endl;
	std::cout << "p2 : " << &p2 << std::endl;

	p1.set(10, 20); 
	p2.set(10, 20); 
}
