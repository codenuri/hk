int x = 0;

int  foo() { return x; } 
int& goo() { return x; } 

int main()
{
	foo() = 20; 
	goo() = 20; 
}
