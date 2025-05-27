//------------------------------------------------------------------------------------------------
//	2025 STL 화56목78				5월 27일 화요일					(12주 2일)
//	6월 19일 목요일 15주 2일 - 기말시험
//------------------------------------------------------------------------------------------------
//	Associative Container	- key와 연관된 value를 항상 정렬상태로 유지한다.
//							  정렬은 key값을 기준으로 한다.
//	set / multiset	- key == value
//	map / multimap	- pair<key, value>
//------------------------------------------------------------------------------------------------
#include <iostream>
#include<fstream>
#include<vector>
#include<algorithm>
#include<set>
#include<ranges>
#include"STRING.h"
#include "save.h"
using namespace std;

extern bool 관찰;				// 관찰하려면 true로 설정

// 강의 자료 "이상한 나라의 앨리스.txt"를 다운
// [1] 여기에 있는 모든 단어를 multiset<STRING>에 저장하라.
// [2] 모두 몇 단어인지 화면에 출력하라.

//---------
int main()
//---------
{
	ifstream in{ "이상한 나라의 앨리스.txt" };
	if (!in)
	{
		cout << "파일?" << endl;
		return 20250527;
	}

	multiset<STRING> ms{ istream_iterator<STRING>{in},{} };
	cout << "읽은 단어 수 - " << ms.size() << endl;
	// 읽은 단어 수 - 26626

	save("main.cpp");

	for (const STRING& 단어 : ms) 
		cout << 단어 << " ";
	cout << endl;

	// 동일 단어가 몇 개 있는지 알려주자
	while (true) {
		cout << "찾을 단어? ";
		STRING 단어;
		cin >> 단어;

		cout << ms.count(단어) << "개가 있습니다." << endl;
	}
	//	정렬된 상태
	//	you가 들어갈 수 있는 하한선과 상한선을 찾음
	//  you의 범위가 나옴. 그 부분 개수를 count
	// 
	//	찾을 단어 ? a
	//	619개가 있습니다.
	//	찾을 단어 ? the
	//	1529개가 있습니다.
	//	찾을 단어 ?
}