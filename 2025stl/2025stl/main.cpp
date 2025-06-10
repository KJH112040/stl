//------------------------------------------------------------------------------------------------
//	2025 STL 화56목78				6월 10일 목요일					(14주 1일)
//	6월 19일 목요일 15주 2일 - 기말시험
//------------------------------------------------------------------------------------------------
//	Algorithm - cppreference
//------------------------------------------------------------------------------------------------
#include <iostream>
#include"STRING.h"
#include "save.h"
using namespace std;

extern bool 관찰;				// 관찰하려면 true로 설정

//---------
int main()
//---------
{
	// cppreference
	// ranges library
	// algorithm library

	//sort(v.begin(), v.end());
	//ranges::sort(v)

	// 지연 평가

	// niebloid (사람 이름)

	// Non-modifying sequence operations
	// 수정하지 않으면서 sequencial 한 operations.
	// 반복자 쌍을 받음. -> 순서대로 돌아감 -> sequencial
	// 원소 수정 x

	// all_of
	// 조건을 전부 만족해?
	// yes / no

	// 인접한 같은 원소 찾기
	// adjacent_find

	// Modifying sequence operations
	// Sequence를 바꾸는 애
	// ex. copy

	// 다음 시간에 sorting 관련 알고리즘 이해
	string s{ "2025. 6. 10" };

	// 잉것도 살리고
	while(true)
	{
		cout << s << endl;
		// 100ms 쉬고
		rotate(s.begin(), s.end(), s.begin() + 1);
	}

	save("main.cpp");
}