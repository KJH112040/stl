//------------------------------------------------------------------------------------------------
//	2025 STL ȭ56��78				6�� 5�� �����					(13�� 2��)
//	6�� 19�� ����� 15�� 2�� - �⸻����
//------------------------------------------------------------------------------------------------
//	Unordered Associative Containers - hash ����
//------------------------------------------------------------------------------------------------
#include <iostream>
#include<unordered_set>
#include<print>
#include"STRING.h"
#include "save.h"
using namespace std;

// setprecision(43)�� ���ô��� ����

extern bool ����;				// �����Ϸ��� true�� ����

template<>
struct std::hash<STRING> {
	size_t operator()(const STRING& s) const {	// �ϰ����� ��Ű�� ���ؼ� const�� ������ �ʴ´ٴ� ������ ) const �̷��� ��� ��.
		return hash<std::string>{}(string{ s.begin(),s.end() });
	}
	// template<class T>
	// struct std::hash{
	//		size_t operator()(const T&){
	//			return 1;
	//		}
	// };
	// ǥ�� hash callable???�� �⺻ ���?
};

//---------
int main()
//---------
{
	//  unordered Associative Container (���� ����)
	//	unordered_map(C++11)
	//	unordered_multimap(C++11)
	//	unordered_set(C++11)
	//	unordered_multiset(C++11)
	//	�� �Ȱ��� �ֵ�.

	unordered_set<STRING, hash<STRING>> us{ "1","22","333","4444" };
	// <STRING,hash<STRING>,equal_to<STRING>>
	// equal_to �� operator ==
	
	for (const STRING& s : us)
		cout << s << endl;

	// ���������� �޸𸮸� ȭ�鿡 ����Ѵ�.
	for (size_t bc/*bucket count*/ = 0; bc < us.bucket_count(); ++bc) {
		print("[{:3}] ", bc);
		for (auto i = us.begin(bc); i != us.end(bc); ++i) {
			print(" -> {:}", std::string{ i->begin(),i->end() });
		}

		cout << endl;

		cout << "�߰��� STRING - ";
		STRING s;
		cin >> s;

		us.insert(s);
	}

	save("main.cpp");
}