// #1. C++버전
// C++98 : 최초의 C++ 표준화
// C++11 : 2011 년에 나온 새로운 표준 ( 기존 문법 + 새로운 다양한 문법 추가 )
//		   이후 C++표준은 3년에 한번씩 발표 하기로 규칙을 정함.
// 현재, C++14/17/20/23 까지 발표된 상태


// #2. how to build
// g++ source.cpp -std=c++14
// g++ source.cpp -std=c++17
// g++ source.cpp -std=c++20
// g++ source.cpp -std=c++23
// g++ source.cpp -std=c++26
// C++ 버전 옵션 생략시 : 각 컴파일러가 지원하는 디폴트 버전으로 컴파일.

// 빌드와 실행을 같이 하려면 첨부된 run.bat 파일 사용
// => run.bat 파일이 있는 폴더를 PATH 환경변수에 등록후
// run source.cpp 


// #3. 표준 출력
#include <iostrea>	// C++98 시절 부터 제공되는 표준 출력 사용(std::cout)
#include <print>	// C++23 에서 추가되는 새로운 출력(std::println)

int main()
{
	std::cout << "hello" << std::endl; 	// until C++20
	std::println("hello");				// since C++23
}

