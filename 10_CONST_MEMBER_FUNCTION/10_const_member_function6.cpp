class vector
{
	int* ptr;
public:
	vector(int sz) 
	{
		ptr = new int[sz];
	}
	~vector() { delete[] ptr;}

	int operator[](int idx) { return ptr[idx];}
};
int main()
{
	vector v(10);
	v[0] = 10;
}