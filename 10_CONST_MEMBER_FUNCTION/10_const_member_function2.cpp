class Rect
{
	int x, y, w, h;
public:
	Rect(int a, int b, int c, int d)
		: x{a}, y{b}, w{c}, h{d} {}

	int getArea() { return w * h; }

};

void foo(Rect r)	   
{
	int n = r.getArea();  	// ???
}

int main()
{
	Rect r(1, 1, 10, 10);	// ?
	int n = r.getArea();	// ?

	foo(r);	//
}



