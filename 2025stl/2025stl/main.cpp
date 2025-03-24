//------------------------------------------------------------------------------------------------
//	2025 STL ȭ56��78	3�� 20�� �����				(3�� 2��)
//------------------------------------------------------------------------------------------------
//	���� ���� �ڷḦ ó���ϱ�	-	Dog�� �а� ����. read/write
//	
//	�̶� Dog ��ü�� �޸� ����
//	1 STACK
//	2 DATA
//	3 free-store (c++������ HEAP�̶�� �θ��� ����)
// 
//	1,2���� 3���� ����		- �޸� ũ�⸦ ���� ������ �� �ִ°�
//	1���� 2���� ����		- �޸� ũ�Ⱑ �󸶳� ū��?
// 
//	���� �ð� �̰� ���� �� �����ϰ� smart pointer�� ���� - �� RAII
//------------------------------------------------------------------------------------------------
#include <iostream>
#include<fstream>
#include<array>
#include "save.h"
using namespace std;

class Dog {
private:			// ���� ������
	string name;
	int id{};


	friend ostream& operator<<(ostream& os, const Dog& dog) {			// friend�� �켱������ ������?
		return os << dog.name << " - " << dog.id;
	}

	friend istream& operator>>(ifstream& is, const Dog& dog) {
		return is.read((char*)&dog, sizeof(Dog));
	}
};

//	[����] e-class�ļ� �ٿ� ���� ���� "Dog 10������"�� binary ���� ������,
//	���� ���� class Dog�� ��Ʈ���� write �Լ��� ����Ͽ� �޸� �״�� �����Ͽ���.

array<Dog, 10'0000> dogs;

//---------
int main() 
//---------
{
	ifstream in{ "Dog 10������",ios::binary };
	if (!in)
		return 20250320;

	//	[����] ���� �ڵ尡 �������� ����ǵ��� �ʿ��� �ڵ带 class Dog�� �߰��϶�.
	for (Dog& dog : dogs)
	{
		in >> dog;				// operator>>(in,dog)
		cout << dog << endl;
	}

	save("main.cpp");
}