//------------------------------------------------------------------------------------------------
//	2025 STL ȭ56��78				6�� 10�� �����					(14�� 1��)
//	6�� 19�� ����� 15�� 2�� - �⸻����
//------------------------------------------------------------------------------------------------
//	Algorithm - cppreference
//------------------------------------------------------------------------------------------------
#include <iostream>
#include"STRING.h"
#include "save.h"
using namespace std;

extern bool ����;				// �����Ϸ��� true�� ����

//---------
int main()
//---------
{
	// cppreference
	// ranges library
	// algorithm library

	//sort(v.begin(), v.end());
	//ranges::sort(v)

	// ���� ��

	// niebloid (��� �̸�)

	// Non-modifying sequence operations
	// �������� �����鼭 sequencial �� operations.
	// �ݺ��� ���� ����. -> ������� ���ư� -> sequencial
	// ���� ���� x

	// all_of
	// ������ ���� ������?
	// yes / no

	// ������ ���� ���� ã��
	// adjacent_find

	// Modifying sequence operations
	// Sequence�� �ٲٴ� ��
	// ex. copy

	// ���� �ð��� sorting ���� �˰��� ����
	string s{ "2025. 6. 10" };

	// �װ͵� �츮��
	while(true)
	{
		cout << s << endl;
		// 100ms ����
		rotate(s.begin(), s.end(), s.begin() + 1);
	}

	save("main.cpp");
}