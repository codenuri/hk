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

	int& operator[](int idx) { return ptr[idx];}
};
int main()
{
	      vector v1(10); // 10 개 배열처럼 사용하겠다는 것
	const vector v2(10); // 10 개 상수 배열처럼 사용하겠다는 것 

	// 아래 ?를 O(되야한다)/X(에러나와야 한다) 로 채워 보세요
	//					// 원하는 동작		현재 상태
	v1[0] = 10;			//	O				O
	v2[0] = 10;			// 	X				X

	int n1 = v1[0];		//	O				O
	int n2 = v2[0];		//	O				X
}