//------------------------------------------------------------------------------------------------
//	2025 STL ȭ56��78				5�� 13�� �����					(10�� 2��)
//	6�� 19�� ����� 15�� 2�� - �⸻����
//------------------------------------------------------------------------------------------------
//	iterator - Iterators are a generalization of pointers that
//	allow a C++ program to work with different data structures in a uniform manner.
// 
//	�ݺ��ڴ� Ŭ������ �ڵ��ؾ� �մϴ�.
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

extern bool ����;				// �����Ϸ��� true�� ����

template<class �ݺ���>
void f(�ݺ��� i)
{
	// � ����
	cout << "�ݺ����� Ÿ�� - " << typeid(�ݺ���::iterator_category).name() << endl;
}

//---------
int main() 
//---------
{
	STRING s{ "2025 5 13" };

	//	[����] �ݺ��ڴ� ����(6 category)�� �ִ�.
	//	�Լ� f�� �ݺ��ڸ� ���ڷ� �޾� � ������ �ݺ������� ȭ�鿡 ����ϴ� �Լ��̴�.
	//	���� �ڵ尡 �������� ����ǰ� ����.
	
	array<int, 2> a;
	f(a.begin());
	//array�� �ݺ��� - class std::_Array_iterator<int,2>

	vector<int> v;
	f(v.begin());
	//class std::_Vector_iterator<class std::_Vector_val<struct std::_Simple_types<int> > >

	f(deque<STRING>::iterator{});
	f(list<int>{}.rbegin());
	f(forward_list<int>::const_iterator{});
	f(ostream_iterator<char>{cout});


	save("main.cpp");
}