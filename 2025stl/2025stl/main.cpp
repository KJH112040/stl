//------------------------------------------------------------------------------------------------
//	2025 STL 화56목78	3월 13일 목요일				(2주 2일)
//------------------------------------------------------------------------------------------------
//	많은 수의 자료를 처리하기	-	파일에 저장하고 읽어 오기
//------------------------------------------------------------------------------------------------
#include <iostream>
#include<fstream>
#include<algorithm>
#include<array>
#include<print>
#include "save.h"
using namespace std;

//	[문제] 파일 "int 1000개.txt"에는 int 값 1000개가 text로 기록되어 있다.
//	이 데이터를 메모리에 저장하라.
//	메모리에 있는 데이터를 화면에 출력하라.		(5분)

//---------
int main() 
//---------
{
	ifstream in{ "int 1000개.txt" };
	if (not in)
		return 20250313;

	array<int, 1000> arr;
	int num;/*, cnt{0};
	while (in >> num) {
		in >> arr[cnt];
		++cnt;
	}*/
	for (int i = 0; i < 1000; ++i) {
		in >> num;
		arr[i] = num;
	}

	for (int num : arr)
		print("{:8}", num);

	save("main.cpp");
}