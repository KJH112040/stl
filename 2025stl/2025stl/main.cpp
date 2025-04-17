//------------------------------------------------------------------------------------------------
//	2025 STL ȭ56��78	4�� 15�� ȭ����				(7�� 1��)
//	�߰����	(30) -	4�� 24��(8�� 2��) �����
//	5�� 2��(ȭ����) -> 6�� 19��(����)
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

extern bool ����;				// �����Ϸ��� true�� ����

//	[����]	Ű���忡�� �Է��� �������� �հ�� ����� ����϶�.

//---------
int main() 
//---------
{
	cout << "������ ������ �Է��ϼ���. ";
	vector<int> v{ istream_iterator<int>{cin}, {} };

	long long sum = accumulate(v.begin(), v.end(), 0LL);		// 0(zero) long long
	cout << "�հ� - " << sum <<endl;
	cout << "��� - " << (double)sum / v.size() << endl;

	save("main.cpp");
}