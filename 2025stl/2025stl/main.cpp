//------------------------------------------------------------------------------------------------
//	2025 STL 화56목78				5월 15일 목요일					(11주 1일)
//	6월 19일 목요일 15주 2일 - 기말시험
//------------------------------------------------------------------------------------------------
//	iterator - Iterators are a generalization of pointers that
//	allow a C++ program to work with different data structures in a uniform manner.
//	Iterator는 pointer를 일반화 한 것이다.
// 
//	반복자는 클래스로 코딩해야 합니다.
//------------------------------------------------------------------------------------------------
#include <iostream>
#include<algorithm>
#include"STRING.h"
#include "save.h"
using namespace std;

extern bool 관찰;				// 관찰하려면 true로 설정

//---------
int main() 
//---------
{
	STRING s{ "2025 5 15" };

	//f(s.begin());		// 랜덤반복자라고 출력해야 표준 반복자다!
	// iterator의 표준이 되려면 제공해야 하는 Iterator primitives : iterator_traits
	// iterator_traits :
	// 1. difference_type	Iter::difference_type
	// 2. value_type		Iter::value_type
	// 3. pointer			Iter::pointer
	// 4. reference			Iter::reference
	// 5. iterator_category	Iter::iterator_category

	// 문제없이 실행되게 하라
	sort(s.begin(), s.end());

	cout << s << endl;		// "  0122555"


	save("main.cpp");
}