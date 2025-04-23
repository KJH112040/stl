//------------------------------------------------------------------------------------------------
//	2025 STL 화56목78				4월 22일 화요일					(8주 1일)
//	중간고사	(30) -	4월 24일(8주 2일) 목요일	-	시험장소 E동 320 (준비 끝난 후 60분)
//	5월 2일(화요일) -> 6월 19일(예정)
//------------------------------------------------------------------------------------------------
//	STL Container - Container are objects that store other objects.
//	1. Sequence Containers
//		array<T,N>
//		vector<T> - dynamic(run-time) array
//		deque<T> - vector보다 더 많은 원소를 담을 수 있다.
//------------------------------------------------------------------------------------------------
#include <iostream>
#include <deque>
#include"STRING.h"
#include "save.h"
using namespace std;

extern bool 관찰;				// 관찰하려면 true로 설정

//---------
int main() 
//---------
{
	관찰 = true;
	deque<STRING> d{"1","22","333","4444","55555"};

	for (const STRING& s : d)
		cout << (void*)&s << endl;
	관찰 = false;



	save("main.cpp");
}