//------------------------------------------------------------------------------------------------
//	2025 STL ȭ56��78				5�� 22�� �����					(12�� 1��)
//	6�� 19�� ����� 15�� 2�� - �⸻����
//------------------------------------------------------------------------------------------------
//	Associative Container	- key�� ������ value�� �׻� ���Ļ��·� �����Ѵ�.
//							  ������ key���� �������� �Ѵ�.
//	set / multiset	- key == value
//	map / multimap	- pair<key, value>
//------------------------------------------------------------------------------------------------
#include <iostream>
#include<set>
#include<ranges>
#include"STRING.h"
#include "save.h"
using namespace std;

extern bool ����;				// �����Ϸ��� true�� ����

// template�� specialization �Ѵ�
template<>
struct std::less<STRING> {
	bool operator()(const STRING& a, const STRING& b)const {
		return a.size() < b.size();
	}
};

//---------
int main() 
//---------
{
	// Ű������ �Է��� s�� �����϶�.
	// s�� ��� ���Ҹ� ȭ�鿡 ����϶�.

	// less�� ����Ͽ� �⺻���ı����� less�� ����Ͽ� ����Ʈ ������ ���ĵǰ� ����
	//set<STRING, less<STRING>> s{ "333","2222","11111","44","5" };
	set<STRING> s { istream_iterator<STRING>{cin},{} };		// {Ű���� ����, Ű���� ��}
	//set<STRING,less<STRING>>{istream_iterator<STRING>{cin},{}};

	for (const STRING& str : s)
		cout << str << endl;

	save("main.cpp");
}