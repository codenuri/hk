// constexpr function
int add1(int a, int b) { return a + b; }
int add2(int a, int b) { return a + b; }

int main()
{
	int x = 1, y = 2;

	int n1 = add1(1, 2);
	int n2 = add2(1, 2);
	int n3 = add2(x, y);
}