//------------------------------------------------------------------------------------------------
//	2025 STL ȭ56��78				4�� 22�� ȭ����					(8�� 1��)
//	�߰����	(30) -	4�� 24��(8�� 2��) �����	-	������� E�� 320 (�غ� ���� �� 60��)
//	5�� 2��(ȭ����) -> 6�� 19��(����)
//------------------------------------------------------------------------------------------------
//	STL Container - Container are objects that store other objects.
//	1. Sequence Containers
//		array<T,N>
//		vector<T> - dynamic(run-time) array
//		deque<T> - vector���� �� ���� ���Ҹ� ���� �� �ִ�.
//------------------------------------------------------------------------------------------------
#include <iostream>
#include <deque>
#include"STRING.h"
#include "save.h"
using namespace std;

extern bool ����;				// �����Ϸ��� true�� ����

//---------
int main() 
//---------
{
	���� = true;
	deque<STRING> d{"1","22","333","4444","55555"};

	for (const STRING& s : d)
		cout << (void*)&s << endl;
	���� = false;



	save("main.cpp");
}