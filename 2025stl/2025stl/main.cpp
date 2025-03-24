//------------------------------------------------------------------------------------------------
//	2025 STL 화56목78	3월 20일 목요일				(3주 2일)
//------------------------------------------------------------------------------------------------
//	많은 수의 자료를 처리하기	-	Dog를 읽고 쓴다. read/write
//	
//	이때 Dog 객체는 메모리 영역
//	1 STACK
//	2 DATA
//	3 free-store (c++에서는 HEAP이라고 부르지 않음)
// 
//	1,2번과 3번의 차이		- 메모리 크기를 언제 결정할 수 있는가
//	1번과 2번의 차이		- 메모리 크기가 얼마나 큰가?
// 
//	다음 시간 이거 조금 더 설명하고 smart pointer로 직행 - 왜 RAII
//------------------------------------------------------------------------------------------------
#include <iostream>
#include<fstream>
#include<array>
#include "save.h"
using namespace std;

class Dog {
private:			// 접근 지시자
	string name;
	int id{};


	friend ostream& operator<<(ostream& os, const Dog& dog) {			// friend는 우선순위가 최하위?
		return os << dog.name << " - " << dog.id;
	}

	friend istream& operator>>(ifstream& is, const Dog& dog) {
		return is.read((char*)&dog, sizeof(Dog));
	}
};

//	[문제] e-classㅔ서 다운 받은 파일 "Dog 10만마리"는 binary 모드로 열었고,
//	위에 적은 class Dog를 스트림의 write 함수를 사용하여 메모리 그대로 저장하였다.

array<Dog, 10'0000> dogs;

//---------
int main() 
//---------
{
	ifstream in{ "Dog 10만마리",ios::binary };
	if (!in)
		return 20250320;

	//	[문제] 다음 코드가 수정없이 실행되도록 필요한 코드를 class Dog에 추가하라.
	for (Dog& dog : dogs)
	{
		in >> dog;				// operator>>(in,dog)
		cout << dog << endl;
	}

	save("main.cpp");
}