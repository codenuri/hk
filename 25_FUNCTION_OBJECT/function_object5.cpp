#include <iostream>
#include <algorithm> 

// sort 알고리즘 자체는 변하지 않지만
// 어떤 기준으로 정렬 할지는 교체 가능하면 좋습니다.
// 비교 함수를 인자로 받아서 사용합니다.

// 장점 : 비교 정책을 교체 할수 있어서 유연성이 좋지만
// 단점 : 내부적으로 이중루프안에서 비교함수를 다시 호출 하므로 
//       성능저하가 있습니다.
//       데이타가 많으면 주의
//       비교 함수를 inline 으로 해도 치환될수 없습니다.(function_object4.cpp참고)

// 비교정책을 교체 할수 있는데,,
// 성능저하가 없게 할수 없을까요 ??? => 함수 객체

void Sort(int* x, int sz, bool(*cmp)(int, int)  )
{
	for (int i = 0; i < sz - 1; i++)
	{
		for (int j = i + 1; j < sz; j++)
		{
//			if (x[i] > x[j])		// 1. 직접 비교				

			if ( cmd(x[i], x[j]) == true )	// 2. 사용자가 인자로 보낸 함수 사용
				std::swap(x[i], x[j]);
		}
	}
}
//=================================
// sort 에 전달할 비교 함수
inline bool cmp1(int a, int b) { return a < b;}
inline bool cmp2(int a, int b) { return a > b;}

int main()
{
	int x[10] = { 1,3,5,7,9,2,4,6,8,10 };
	Sort(x, 10, cmp1);	// sort 의 3번째 인자로 비교 정책 전달
	Sort(x, 10, cmp2);
}

