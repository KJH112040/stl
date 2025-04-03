//------------------------------------------------------------------------------------------------
//	2025 STL ȭ56��78	4�� 3�� �����				(5�� 2��)
//	�߰����	(30) -	4�� 24��(8�� 2��) �����
//	����		(30) - 4�� 10�� ����
//------------------------------------------------------------------------------------------------
//	STRING - std::string�� ������ Ŭ����, STL ǥ�� �����̳ʰ� �ǵ���..
//------------------------------------------------------------------------------------------------
#include <iostream>
#include<string>
#include "save.h"
using namespace std;

// public, private, protected ---> acssess modifiy�������?
class STRING {
public:
	STRING(const char* s) :len{strlen(s)} {		// [] (array) -> *(pointer)�� collapsing 
		// p = new char[len];	-> unique_ptr�̱⿡ �Ұ����� �۾�, unique_ptr�� �ڿ��� �����ϴ� ��
		p.reset();
		p = make_unique<char[]>(len);		// Lvalue : ��������δ� location value (left value�ƴ�...)
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
	STRING s{ "std::string�� ������ Ŭ����" };

	cout << s.size() << endl;		// s�� Ȯ���� �ڿ��� ����Ʈ ��

	cout << s << endl;

	//	27
	//	std::string�� ������ Ŭ����

	save("main.cpp");
}