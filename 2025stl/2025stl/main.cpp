//------------------------------------------------------------------------------------------------
//	2025 STL ȭ56��78				5�� 27�� ȭ����					(12�� 2��)
//	6�� 19�� ����� 15�� 2�� - �⸻����
//------------------------------------------------------------------------------------------------
//	Associative Container	- key�� ������ value�� �׻� ���Ļ��·� �����Ѵ�.
//							  ������ key���� �������� �Ѵ�.
//	set / multiset	- key == value
//	map / multimap	- pair<key, value>
//------------------------------------------------------------------------------------------------
#include <iostream>
#include<fstream>
#include<vector>
#include<algorithm>
#include<set>
#include<ranges>
#include"STRING.h"
#include "save.h"
using namespace std;

extern bool ����;				// �����Ϸ��� true�� ����

// ���� �ڷ� "�̻��� ������ �ٸ���.txt"�� �ٿ�
// [1] ���⿡ �ִ� ��� �ܾ multiset<STRING>�� �����϶�.
// [2] ��� �� �ܾ����� ȭ�鿡 ����϶�.

//---------
int main()
//---------
{
	ifstream in{ "�̻��� ������ �ٸ���.txt" };
	if (!in)
	{
		cout << "����?" << endl;
		return 20250527;
	}

	multiset<STRING> ms{ istream_iterator<STRING>{in},{} };
	cout << "���� �ܾ� �� - " << ms.size() << endl;
	// ���� �ܾ� �� - 26626

	save("main.cpp");

	for (const STRING& �ܾ� : ms) 
		cout << �ܾ� << " ";
	cout << endl;

	// ���� �ܾ �� �� �ִ��� �˷�����
	while (true) {
		cout << "ã�� �ܾ�? ";
		STRING �ܾ�;
		cin >> �ܾ�;

		cout << ms.count(�ܾ�) << "���� �ֽ��ϴ�." << endl;
	}
	//	���ĵ� ����
	//	you�� �� �� �ִ� ���Ѽ��� ���Ѽ��� ã��
	//  you�� ������ ����. �� �κ� ������ count
	// 
	//	ã�� �ܾ� ? a
	//	619���� �ֽ��ϴ�.
	//	ã�� �ܾ� ? the
	//	1529���� �ֽ��ϴ�.
	//	ã�� �ܾ� ?
}