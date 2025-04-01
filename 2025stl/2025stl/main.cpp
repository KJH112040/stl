//------------------------------------------------------------------------------------------------
//	2025 STL ȭ56��78	3�� 27�� �����				(4�� 2��)
//------------------------------------------------------------------------------------------------
//	4�� 24�� (8�� 2����) - �߰����
//	RAII : �ڿ��� �����ֱ⸦ ��ü�� �����ֱ⿡ ����ȭ
//	������ ���� : Callable
//	A Callable type is a type for which the INVOKE and INVOKE<R> operations 
// (used by, e.g., std::function, std::bind, and std::thread::thread) are applicable.
//	=> Callable type - ȣ�Ⱑ���� Ÿ��
//	1. 
//------------------------------------------------------------------------------------------------
#include <iostream>
#include<random>
#include<array>
#include<print>
#include<ranges>
#include<algorithm>
#include<chrono>
#include "save.h"
using namespace std;

//	[����] ���� int 1000�� ���� �޸𸮿� ��������.
//	���� int ���� [ 0, 1'000'0000 ) ==> 0���� 999'9999���� ���� ������
//	C++����� sort�� ����Ͽ� ������������ �����϶�.
//	������ ����� �տ������� 1000���� ȭ�鿡 ����϶�.

array<int, 1'000'0000> a;

default_random_engine dre;
uniform_int_distribution<int> uid{ 0,999'9999 };

bool ��������(const int a, const int b) {
	return a < b;
}

//---------
int main() 
//---------
{
	{
		for (int& num : a)
			num = uid(dre);

		//	���Ŀ� �ɸ��� �ð� ����
		auto ���� = chrono::high_resolution_clock::now();	//	�����ġ ����
		sort<array<int,1'000'0000>::iterator>(a.begin(), a.end(), ��������);					//	default ���� operator <
		auto �� = chrono::high_resolution_clock::now();		//	�����ġ ��

		cout << "����ð�(ms) - " << chrono::duration_cast<chrono::milliseconds>(�� - ����) << endl;
	}

	{	// ������������ ����
		for (int& num : a)
			num = uid(dre);

		//	���Ŀ� �ɸ��� �ð� ����
		auto ���� = chrono::high_resolution_clock::now();	//	�����ġ ����
		sort(a.begin(), a.end(), [](const int a, const int b) {return a > b; });					//	default ���� operator <
		auto �� = chrono::high_resolution_clock::now();		//	�����ġ ��

		cout << "����ð�(ms) - " << chrono::duration_cast<chrono::milliseconds>(�� - ����) << endl;
	}

	//	�տ��� ���� 1000���� ȭ�� ���
	//for (int num:a	| ranges::views::take(1000))
	//	print("{:8}", num);
	//cout << endl;

	save("main.cpp");
}