//------------------------------------------------------------------------------------------------
//	2025 STL 화56목78	4월 15일 화요일				(7주 1일)
//	중간고사	(30) -	4월 24일(8주 2일) 목요일
//	5월 2일(화요일) -> 6월 19일(예정)
//------------------------------------------------------------------------------------------------
//	STL Container - Container are objects that store other objects.
//	1. Sequence Containers
//		array<T,N>
//		vector<T> - dynamic array
//------------------------------------------------------------------------------------------------
#include <iostream>
#include <vector>
#include<numeric>
#include"STRING.h"
#include "save.h"
using namespace std;

extern bool 관찰;				// 관찰하려면 true로 설정

//	[문제]	키보드에서 입력한 정수값의 합계와 평균을 출력하라.

//---------
int main() 
//---------
{
	cout << "정수를 마음껏 입력하세요. ";
	vector<int> v{ istream_iterator<int>{cin}, {} };

	long long sum = accumulate(v.begin(), v.end(), 0LL);		// 0(zero) long long
	cout << "합계 - " << sum <<endl;
	cout << "평균 - " << (double)sum / v.size() << endl;

	save("main.cpp");
}