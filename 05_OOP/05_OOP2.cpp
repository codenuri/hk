// 67page
#include <iostream>

struct Rect
{
	int left;
	int top;
	int right;
	int bottom;
};

int get_rect_area(int left, int top, int right, int bottom)
{
	return (right - left) * (bottom - top);
}

void draw_rect(int left, int top, int right, int bottom)
{
	std::cout << "draw rect" << std::endl;
}

int main()
{
	int n1 = get_rect_area(1, 1, 10, 10);
	draw_rect(1, 1, 10, 10);
}