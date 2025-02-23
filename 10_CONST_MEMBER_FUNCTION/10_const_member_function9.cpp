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

	int& operator[](int idx)       { return ptr[idx];}
	int  operator[](int idx) const { return ptr[idx];}
};
int main()
{
//	const std::vector<int> v3 = {1,2,3};
//	v3[0] = 10; // error
//	int n = v3[0]; // ok

	      vector v1(10); 
	const vector v2(10); 


	//					// 원하는 동작		현재 상태
	v1[0] = 10;			//	O				O
	v2[0] = 10;			// 	X				X

	int n1 = v1[0];		//	O				O
	int n2 = v2[0];		//	O				O
}