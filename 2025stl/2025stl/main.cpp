//------------------------------------------------------------------------------------------------
//	2025 STL ȭ56��78				5�� 29�� �����					(13�� 1��)
//	6�� 19�� ����� 15�� 2�� - �⸻����
//------------------------------------------------------------------------------------------------
//	Associative Container	- key�� ������ value�� �׻� ���Ļ��·� �����Ѵ�.
//							  ������ key���� �������� �Ѵ�.
//	set / multiset	- key == value
//	map / multimap	- pair<key, value>
//------------------------------------------------------------------------------------------------
#include <iostream>
#include<fstream>
#include<algorithm>
#include<map>
#include<print>
#include<format>
#include"STRING.h"
#include "save.h"
using namespace std;

extern bool ����;				// �����Ϸ��� true�� ����

// ���� �ڷ� "�̻��� ������ �ٸ���.txt"�� �ٿ�
// [1] ���⿡ �ִ� ��� �ܾ multimap<STRING,size_t>�� �����϶�.
// [2] ��� �� �ܾ����� ȭ�鿡 ����϶�.
// [3] �ܾ�� ��� Ƚ���� ȭ�鿡 ����϶�.


//---------
int main()
//---------
{
	ifstream in{ "�̻��� ������ �ٸ���.txt" };
	if (!in)
	{
		cout << "����?" << endl;
		return 20250529;
	}

	map<STRING, size_t> wordNum;

	STRING �ܾ�;
	while (in >> �ܾ�)
		wordNum[�ܾ�]++;
	
	for (auto [�ܾ�, ����] : wordNum)		// �ܾ STRING�̶� formatting�� �� ��.
		cout << �ܾ� << " - " << ���� << endl;
		//println("{:20} - {:}", (char*)(�ܾ�[0]), ����);

	save("main.cpp");
}