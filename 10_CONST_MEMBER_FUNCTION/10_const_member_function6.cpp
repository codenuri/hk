class vector
{
	int* ptr;
	int size;
public:
	vector(int sz) : size(sz)
	{
		ptr = new int[sz];
	}
	~vector() { delete[] ptr;}

	int operator[](int idx) { return ptr[idx];}
};
int main()
{
	vector v(10);
	v[0] = 10;	// v.operator[](0) = 10
}