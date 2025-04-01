//------------------------------------------------------------------------------------------------
//	2025 STL ȭ56��78	4�� 1�� ȭ����				(5�� 1��)
//	�߰����	(30) -	4�� 24��(8�� 2��) �����
//	����		(30) - 4�� 10�� ����
//------------------------------------------------------------------------------------------------
//	Callable
//------------------------------------------------------------------------------------------------
#include <iostream>
#include<fstream>
#include<array>
#include<algorithm>
#include "save.h"
using namespace std;

//	[����] Dog 10�� ������ ������ ���� ���� "Dog �ʸ�����"�� �����Ͽ���.
//	������ ���� �ڵ�� ������.
//		ofstream out{ "Dog �ʸ�����" };
//
//	Dog ��ü�� class Dog�� friend operator<<�� ����Ͽ� �����Ͽ���.
//
//	[����] �� ���Ͽ��� ��Ȯ�ϰ� 10�� ���� Dog ��ü�� ����Ǿ� �ִ�.
//	���Ͽ� ����� Dog ��ü�� ��� �о� �޸𸮿� �����϶�.
//	���� ������ ��ü�� ������ ȭ�鿡 ����ϰ� �������� ��� ������ �����.
//	�޸𸮿� ����� Dog ��ü�� ��� name ���� ���� ������������ �����϶�.
//	���ĵ� Dog ��ü�� �տ��� ���� 1000���� ȭ�鿡 ����϶�.

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
	ifstream in{ "Dog �ʸ�����" };
	in.read((char*)dogs.data(), dogs.size() * sizeof(Dog));

	cout << "������ ��ü�� ���� -" << dogs[9'9999] << endl;

	sort(dogs.begin(), dogs.end(), [](Dog a, Dog b) {return a.name_len() < b.name_len(); });

	for (int i = 0; i < 1000; ++i)
		cout << dogs[i] << " ";
	cout << endl;

	//save("main.cpp");
}