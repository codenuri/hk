#include <iostream>

int main()
{
	const int c = 10;

	int* p = &c;

	*p = 20;
}
