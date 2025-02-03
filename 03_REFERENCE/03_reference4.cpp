struct BigData
{
	int buff[1024];
};

void foo(int n)
{
	n = 20;
}
void goo( BigData bd ) 
{
}
int main()
{
	int x = 100;
	foo(x);

	BigData b;
	goo(b);
}
