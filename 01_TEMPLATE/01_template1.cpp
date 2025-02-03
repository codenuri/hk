// 35 page
// 함수 오버로딩
// 장점 : 사용자 입장에서는 한개의 함수 처럼 생각하게 된다.(일관된 형태의 라이브러리)
// 단점 : 유사(동일)한 코드를 반복해서 작성하게 된다.

int square(int a)
{
	return a * a;
}

double square(double a)
{
	return a * a;
}

int main()
{
	square(3);
	square(3.4);
}














