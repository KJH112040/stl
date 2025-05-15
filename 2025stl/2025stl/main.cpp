//------------------------------------------------------------------------------------------------
//	2025 STL ȭ56��78				5�� 15�� �����					(11�� 1��)
//	6�� 19�� ����� 15�� 2�� - �⸻����
//------------------------------------------------------------------------------------------------
//	iterator - Iterators are a generalization of pointers that
//	allow a C++ program to work with different data structures in a uniform manner.
//	Iterator�� pointer�� �Ϲ�ȭ �� ���̴�.
// 
//	�ݺ��ڴ� Ŭ������ �ڵ��ؾ� �մϴ�.
//------------------------------------------------------------------------------------------------
#include <iostream>
#include<algorithm>
#include"STRING.h"
#include "save.h"
using namespace std;

extern bool ����;				// �����Ϸ��� true�� ����

//---------
int main() 
//---------
{
	STRING s{ "2025 5 15" };

	//f(s.begin());		// �����ݺ��ڶ�� ����ؾ� ǥ�� �ݺ��ڴ�!
	// iterator�� ǥ���� �Ƿ��� �����ؾ� �ϴ� Iterator primitives : iterator_traits
	// iterator_traits :
	// 1. difference_type	Iter::difference_type
	// 2. value_type		Iter::value_type
	// 3. pointer			Iter::pointer
	// 4. reference			Iter::reference
	// 5. iterator_category	Iter::iterator_category

	// �������� ����ǰ� �϶�
	sort(s.begin(), s.end());

	cout << s << endl;		// "  0122555"


	save("main.cpp");
}