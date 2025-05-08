//------------------------------------------------------------------------------------------------
//	2025 STL 화56목78				5월 8일 목요일					(10주 1일)
//	6월 19일 목요일 15주 2일 - 기말시험
//------------------------------------------------------------------------------------------------
//	STL Container - Container are objects that store other objects.
//	1. Sequence Containers
//		array<T,N>
//		vector<T>		- push_back() O(1)
//		deque<T>		- push_front() / push_back() O(1)
//		list<T>			- node 기반, 임의의 위치에서 삽입과 삭제 O(1)
//						  대표 동작 : sort(), unique(), merge(), splice();
//		forward_list<T>	- 
//						It is intended that forward_list have zero space or time overhead
//						relative to a hand-written C-style singly linked list.
//						Features that would conflict with that goal have been omitted.
//	span:
//	The class template span describes an object that can refer to a contiguous sequence of objects 
//	with the first element of the sequence at position zero.
//	A span can either have a static extent, in which case the number of elements 
//	in the sequence is known at compile-time and encoded in the type, or a dynamic extent.
//------------------------------------------------------------------------------------------------
#include <iostream>
#include<array>
#include<vector>
#include<deque>
#include<span>
#include"STRING.h"
#include "save.h"
using namespace std;

extern bool 관찰;				// 관찰하려면 true로 설정

void f(span<int> s)
{
	for (auto i = s.rbegin(); i != s.rend(); ++i)
		cout << *i << " ";
	cout << endl;
}

//---------
int main() 
//---------
{
	int a[]{ 1,2,3,4,5,6,7 };
	f(a);

	vector<int> v{ begin(a),end(a) };	 // == { &a[0],&a[7] }; 같은 표현
	f(v);

	

	save("main.cpp");
}