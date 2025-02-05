#include <iostream>

void draw_line(int x1, int y1, int x2, int y2) {}

int main()
{
	// (10, 10) ~ (20, 20) 에 선을 그리고 싶다.

	// 방법 #1. 변수를 만들어서 함수에 전달하자.
	int x1 = 10, y1 = 10;
	int x2 = 20, y2 = 20;

	draw_line(x1, y1, x2, y2);

	// 방법 #2. 리터럴 사용 - 당연히 좋은 코드
	draw_line(10, 10, 20, 20);
}