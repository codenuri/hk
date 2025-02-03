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

	// 핵심 #1. reference 반환을 사용하면 함수 호출이 등호의 왼쪽에 올수 있습니다.
	// 그래서 "v[0] = 10" 이 가능해 집니다.
	
	int& operator[](int idx) { return ptr[idx];}
};
int main()
{
	vector v(10);
	v[0] = 10;	// v.operator[](0) = 10
}