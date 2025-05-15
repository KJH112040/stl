//------------------------------------------------------------------------------------------------
//	2025 STL 화56목78				5월 13일 목요일					(10주 2일)
//	6월 19일 목요일 15주 2일 - 기말시험
//------------------------------------------------------------------------------------------------
//	iterator - Iterators are a generalization of pointers that
//	allow a C++ program to work with different data structures in a uniform manner.
// 
//	반복자는 클래스로 코딩해야 합니다.
//------------------------------------------------------------------------------------------------
#include <iostream>
#include<string>
#include<iterator>
#include<array>
#include<vector>
#include<deque>
#include<list>
#include<forward_list>
#include"STRING.h"
#include "save.h"
using namespace std;

extern bool 관찰;				// 관찰하려면 true로 설정

template<class 반복자>
void f(반복자 i)
{
	// 어떤 종류
	cout << "반복자의 타입 - " << typeid(반복자::iterator_category).name() << endl;
}

//---------
int main() 
//---------
{
	STRING s{ "2025 5 13" };

	//	[문제] 반복자는 종류(6 category)가 있다.
	//	함수 f는 반복자를 인자로 받아 어떤 종류의 반복자인지 화면에 출력하는 함수이다.
	//	다음 코드가 문제없이 실행되게 하자.
	
	array<int, 2> a;
	f(a.begin());
	//array의 반복자 - class std::_Array_iterator<int,2>

	vector<int> v;
	f(v.begin());
	//class std::_Vector_iterator<class std::_Vector_val<struct std::_Simple_types<int> > >

	f(deque<STRING>::iterator{});
	f(list<int>{}.rbegin());
	f(forward_list<int>::const_iterator{});
	f(ostream_iterator<char>{cout});


	save("main.cpp");
}