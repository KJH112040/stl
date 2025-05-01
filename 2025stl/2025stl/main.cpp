//------------------------------------------------------------------------------------------------
//	2025 STL ȭ56��78				5�� 1�� �����					(9�� 2��)
//	5�� 6��(ȭ����) -> 6�� 19��(����)
//------------------------------------------------------------------------------------------------
//	STL Container - Container are objects that store other objects.
//	1. Sequence Containers
//		array<T,N>
//		vector<T> - push_back() O(1)
//		deque<T>  - push_front() / push_back() O(1)
//		list<T>	  - node ���, ������ ��ġ���� ���԰� ���� O(1)
//------------------------------------------------------------------------------------------------
#include <iostream>
#include <list>
#include<fstream>
#include<algorithm>
#include"STRING.h"
#include "save.h"
using namespace std;

extern bool ����;				// �����Ϸ��� true�� ����

//---------
int main() 
//---------
{
	//	[����] "main.cpp"�� �ܾ list�� �����϶�.
	//	ã�� �ܾ ������� ������ ����. ������ list�� �� ��° �ܾ����� ����� ����.

	save("main.cpp");

	ifstream in{"main.cpp"};
	if (not in)
		return 20250501;

	list<STRING> �ܾ��{ istream_iterator<STRING>{in},{} };
	while (true) {
		cout << "ã���� �ܾ�? ";
		STRING �ܾ�;
		cin >> �ܾ�;

		auto res = find(�ܾ��.begin(), �ܾ��.end(), �ܾ�);		// �ݺ��ڷ� ��ȯ
		if (res == �ܾ��.end())
			cout << �ܾ� << " - ���� �ܾ��Դϴ�." << endl;
		else
			cout << "ã�ҽ��ϴ�." << endl;
	}


}