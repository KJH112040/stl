//------------------------------------------------------------------------------------------------
//	2025 STL ȭ56��78	3�� 25�� ȭ����				(4�� 1��)
//------------------------------------------------------------------------------------------------
//	
//------------------------------------------------------------------------------------------------
#include <iostream>
#include<fstream>
#include<algorithm>
#include "save.h"
using namespace std;

//	[����] "����.cpp"�� ���� �߿� �ҹ��ڸ� ��� �빮�ڷ� �ٲ� "���� �빮��.cpp"�� �����϶�

//---------
int main() 
//---------
{
	ifstream in{ "main.cpp" };
	if (!in)
		return 20250325;

	ofstream out{ "���� �빮��.cpp" };

	transform(istreambuf_iterator<char>{in}, {}, ostreambuf_iterator<char>{out},
		[](char c) {return toupper(c); });

	save("main.cpp");
}