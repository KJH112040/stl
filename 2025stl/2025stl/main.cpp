//------------------------------------------------------------------------------------------------
//	2025 STL 화56목78	3월 27일 목요일				(4주 2일)
//------------------------------------------------------------------------------------------------
//	4월 24일 (8주 2일차) - 중간고사
//	RAII : 자원의 생명주기를 객체의 생명주기에 동기화
//	오늘의 주제 : Callable
//	A Callable type is a type for which the INVOKE and INVOKE<R> operations 
// (used by, e.g., std::function, std::bind, and std::thread::thread) are applicable.
//	=> Callable type - 호출가능한 타입
//	1. 
//------------------------------------------------------------------------------------------------
#include <iostream>
#include<random>
#include<array>
#include<print>
#include<ranges>
#include<algorithm>
#include<chrono>
#include "save.h"
using namespace std;

//	[문제] 랜덤 int 1000만 개를 메모리에 저장하자.
//	랜덤 int 값은 [ 0, 1'000'0000 ) ==> 0부터 999'9999까지 값을 갖도록
//	C++언어의 sort를 사용하여 오름차순으로 정렬하라.
//	정렬한 결과를 앞에서부터 1000개만 화면에 출력하라.

array<int, 1'000'0000> a;

default_random_engine dre;
uniform_int_distribution<int> uid{ 0,999'9999 };

bool 오름차순(const int a, const int b) {
	return a < b;
}

//---------
int main() 
//---------
{
	{
		for (int& num : a)
			num = uid(dre);

		//	정렬에 걸리는 시간 측정
		auto 시작 = chrono::high_resolution_clock::now();	//	스톱워치 시작
		sort<array<int,1'000'0000>::iterator>(a.begin(), a.end(), 오름차순);					//	default 정렬 operator <
		auto 끝 = chrono::high_resolution_clock::now();		//	스톱워치 끝

		cout << "경과시간(ms) - " << chrono::duration_cast<chrono::milliseconds>(끝 - 시작) << endl;
	}

	{	// 내림차순으로 정렬
		for (int& num : a)
			num = uid(dre);

		//	정렬에 걸리는 시간 측정
		auto 시작 = chrono::high_resolution_clock::now();	//	스톱워치 시작
		sort(a.begin(), a.end(), [](const int a, const int b) {return a > b; });					//	default 정렬 operator <
		auto 끝 = chrono::high_resolution_clock::now();		//	스톱워치 끝

		cout << "경과시간(ms) - " << chrono::duration_cast<chrono::milliseconds>(끝 - 시작) << endl;
	}

	//	앞에서 부터 1000개를 화면 출력
	//for (int num:a	| ranges::views::take(1000))
	//	print("{:8}", num);
	//cout << endl;

	save("main.cpp");
}