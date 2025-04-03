//------------------------------------------------------------------------------------------------
//	2025 STL 화56목78	4월 3일 목요일				(5주 2일)
//	중간고사	(30) -	4월 24일(8주 2일) 목요일
//	과제		(30) - 4월 10일 설명
//------------------------------------------------------------------------------------------------
//	STRING - std::string과 유사한 클래스, STL 표준 컨테이너가 되도록..
//------------------------------------------------------------------------------------------------
#include <iostream>
#include<string>
#include "save.h"
using namespace std;

// public, private, protected ---> acssess modifiy모디파이?
class STRING {
public:
	STRING(const char* s) :len{strlen(s)} {		// [] (array) -> *(pointer)로 collapsing 
		// p = new char[len];	-> unique_ptr이기에 불가능한 작업, unique_ptr은 자원을 독점하는 놈
		p.reset();
		p = make_unique<char[]>(len);		// Lvalue : 현대식으로는 location value (left value아님...)
		memcpy(p.get(), s, len);					// DMA : Direct Memory Acssess
	};

	size_t size() const {
		return len;
	}
private:
	size_t len{};
	unique_ptr<char[]> p{};

	friend ostream& operator<<(ostream & os, const STRING& str) {
		for (int i = 0; i < str.len; ++i)
			os << str.p[i];
		return os;
	}
};

//---------
int main() 
//---------
{
	STRING s{ "std::string과 유사한 클래스" };

	cout << s.size() << endl;		// s가 확보한 자원의 바이트 수

	cout << s << endl;

	//	27
	//	std::string과 유사한 클래스

	save("main.cpp");
}