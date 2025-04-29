//------------------------------------------------------------------------------------------------
//	2025 STL 화56목78				4월 29일 화요일					(9주 1일)
//	5월 6일(화요일) -> 6월 19일(예정)
//------------------------------------------------------------------------------------------------
//	STL Container - Container are objects that store other objects.
//	1. Sequence Containers
//		array<T,N>
//		vector<T> - dynamic(run-time) array
//		deque<T>  - vector보다 더 많은 원소를 담을 수 있다.
//		
//------------------------------------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <list>
#include<algorithm>
#include"STRING.h"
#include "save.h"
using namespace std;

extern bool 관찰;				// 관찰하려면 true로 설정

//---------
int main() 
//---------
{
	관찰 = true;
	list<STRING> cont{ "1","333","55555","4444","22" };

	ranges::sort(cont.begin(), cont.end());

	for (const STRING& s : cont)
		cout << s << endl;

	
	관찰 = false;
	save("main.cpp");
}