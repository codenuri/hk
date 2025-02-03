struct BigData
{
	int buff[1024];
};


// call by value : 복사본 생성. 원본 데이타 수정 할수 없음.
//					함수간 독립성이 생기므로 안전하다!! 아주 좋은 코드. 		
void foo(int n)
{
	n = 20;
}

// 그런데, 인자의 타입이 크기가 크다면 
// call by value 는 복사본의 오버헤드가 크다.
//void goo( BigData bd ) 

// optimization : 메모리 복사본을 없애기 위해서 call by reference 
// safety       : 안전성(함수간 독립)을 위해서 const 
void goo( const BigData& bd ) 
{
//	bd.member = 10; // error
}

int main()
{
	int x = 100;
	foo(x);


	BigData b;
	goo(b);
}
