//------------------------------------------------------------------------------------------------
//	2025 STL ȭ56��78				4�� 29�� ȭ����					(9�� 1��)
//	5�� 6��(ȭ����) -> 6�� 19��(����)
//------------------------------------------------------------------------------------------------
//	STL Container - Container are objects that store other objects.
//	1. Sequence Containers
//		array<T,N>
//		vector<T> - dynamic(run-time) array
//		deque<T>  - vector���� �� ���� ���Ҹ� ���� �� �ִ�.
//		
//------------------------------------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <list>
#include<algorithm>
#include"STRING.h"
#include "save.h"
using namespace std;

extern bool ����;				// �����Ϸ��� true�� ����

//---------
int main() 
//---------
{
	���� = true;
	list<STRING> cont{ "1","333","55555","4444","22" };

	ranges::sort(cont.begin(), cont.end());

	for (const STRING& s : cont)
		cout << s << endl;

	
	���� = false;
	save("main.cpp");
}