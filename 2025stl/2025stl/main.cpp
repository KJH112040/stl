//------------------------------------------------------------------------------------------------
//	2025 STL 화56목78	3월 25일 화요일				(4주 1일)
//------------------------------------------------------------------------------------------------
//	
//------------------------------------------------------------------------------------------------
#include <iostream>
#include<fstream>
#include<algorithm>
#include "save.h"
using namespace std;

//	[문제] "메인.cpp"의 내용 중에 소문자를 모두 대문자로 바꿔 "메인 대문자.cpp"에 저장하라

//---------
int main() 
//---------
{
	ifstream in{ "main.cpp" };
	if (!in)
		return 20250325;

	ofstream out{ "메인 대문자.cpp" };

	transform(istreambuf_iterator<char>{in}, {}, ostreambuf_iterator<char>{out},
		[](char c) {return toupper(c); });

	save("main.cpp");
}