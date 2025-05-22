//------------------------------------------------------------------------------------------------
//	2025 STL 화56목78				5월 22일 목요일					(12주 1일)
//	6월 19일 목요일 15주 2일 - 기말시험
//------------------------------------------------------------------------------------------------
//	Associative Container	- key와 연관된 value를 항상 정렬상태로 유지한다.
//							  정렬은 key값을 기준으로 한다.
//	set / multiset	- key == value
//	map / multimap	- pair<key, value>
//------------------------------------------------------------------------------------------------
#include <iostream>
#include<set>
#include<ranges>
#include"STRING.h"
#include "save.h"
using namespace std;

extern bool 관찰;				// 관찰하려면 true로 설정

// template을 specialization 한다
template<>
struct std::less<STRING> {
	bool operator()(const STRING& a, const STRING& b)const {
		return a.size() < b.size();
	}
};

//---------
int main() 
//---------
{
	// 키보드의 입력을 s에 저장하라.
	// s의 모든 원소를 화면에 출력하라.

	// less를 사용하여 기본정렬기준인 less를 사용하여 바이트 순으로 정렬되게 하자
	//set<STRING, less<STRING>> s{ "333","2222","11111","44","5" };
	set<STRING> s { istream_iterator<STRING>{cin},{} };		// {키보드 시작, 키보드 끝}
	//set<STRING,less<STRING>>{istream_iterator<STRING>{cin},{}};

	for (const STRING& str : s)
		cout << str << endl;

	save("main.cpp");
}