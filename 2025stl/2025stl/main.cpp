//------------------------------------------------------------------------------------------------
//	2025 STL 화56목78	4월 1일 화요일				(5주 1일)
//	중간고사	(30) -	4월 24일(8주 2일) 목요일
//	과제		(30) - 4월 10일 설명
//------------------------------------------------------------------------------------------------
//	Callable
//------------------------------------------------------------------------------------------------
#include <iostream>
#include<fstream>
#include<array>
#include<algorithm>
#include "save.h"
using namespace std;

//	[설명] Dog 10만 마리를 다음과 같이 파일 "Dog 십만마리"에 저장하였다.
//	파일은 다음 코드로 열었다.
//		ofstream out{ "Dog 십만마리" };
//
//	Dog 객체는 class Dog의 friend operator<<를 사용하여 저장하였다.
//
//	[문제] 이 파일에는 정확하게 10만 개의 Dog 객체가 저장되어 있다.
//	파일에 저장된 Dog 객체를 모두 읽어 메모리에 저장하라.
//	제일 마지막 객체의 정보를 화면에 출력하고 답지에도 출력 내용을 적어라.
//	메모리에 저장된 Dog 객체를 멤버 name 길이 기준 오름차순으로 정렬하라.
//	정렬된 Dog 객체를 앞에서 부터 1000개를 화면에 출력하라.

class Dog {
public:
	int name_len() {
		return sizeof(name);
	}
private:
	string name;
	int id;
	
	friend ostream& operator<<(ostream& os, Dog dog) {
		return os << dog.id << " " << dog.name << " ";
	}
};

array<Dog, 10'0000> dogs;

//---------
int main() 
//---------
{
	ifstream in{ "Dog 십만마리" };
	in.read((char*)dogs.data(), dogs.size() * sizeof(Dog));

	cout << "마지막 객체의 정보 -" << dogs[9'9999] << endl;

	sort(dogs.begin(), dogs.end(), [](Dog a, Dog b) {return a.name_len() < b.name_len(); });

	for (int i = 0; i < 1000; ++i)
		cout << dogs[i] << " ";
	cout << endl;

	//save("main.cpp");
}