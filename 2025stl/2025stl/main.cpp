//------------------------------------------------------------------------------------------------
//	2025 STL 화56목78				6월 5일 목요일					(13주 2일)
//	6월 19일 목요일 15주 2일 - 기말시험
//------------------------------------------------------------------------------------------------
//	Unordered Associative Containers - hash 구조
//------------------------------------------------------------------------------------------------
#include <iostream>
#include<unordered_set>
#include<print>
#include"STRING.h"
#include "save.h"
using namespace std;

// setprecision(43)은 구시대의 유물

extern bool 관찰;				// 관찰하려면 true로 설정

template<>
struct std::hash<STRING> {
	size_t operator()(const STRING& s) const {	// 일관성을 지키기 위해서 const가 변하지 않는다는 도장을 ) const 이렇게 찍는 것.
		return hash<std::string>{}(string{ s.begin(),s.end() });
	}
	// template<class T>
	// struct std::hash{
	//		size_t operator()(const T&){
	//			return 1;
	//		}
	// };
	// 표준 hash callable???의 기본 모습?
};

//---------
int main()
//---------
{
	//  unordered Associative Container (교재 참조)
	//	unordered_map(C++11)
	//	unordered_multimap(C++11)
	//	unordered_set(C++11)
	//	unordered_multiset(C++11)
	//	다 똑같은 애들.

	unordered_set<STRING, hash<STRING>> us{ "1","22","333","4444" };
	// <STRING,hash<STRING>,equal_to<STRING>>
	// equal_to 는 operator ==
	
	for (const STRING& s : us)
		cout << s << endl;

	// 언오더드셋의 메모리를 화면에 출력한다.
	for (size_t bc/*bucket count*/ = 0; bc < us.bucket_count(); ++bc) {
		print("[{:3}] ", bc);
		for (auto i = us.begin(bc); i != us.end(bc); ++i) {
			print(" -> {:}", std::string{ i->begin(),i->end() });
		}

		cout << endl;

		cout << "추가할 STRING - ";
		STRING s;
		cin >> s;

		us.insert(s);
	}

	save("main.cpp");
}