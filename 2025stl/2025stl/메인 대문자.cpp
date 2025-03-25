//------------------------------------------------------------------------------------------------
//	2025 STL 화56목78	3월 25일 화요일				(4주 1일)
//------------------------------------------------------------------------------------------------
//	
//------------------------------------------------------------------------------------------------
#INCLUDE <IOSTREAM>
#INCLUDE<FSTREAM>
#INCLUDE<ALGORITHM>
#INCLUDE "SAVE.H"
USING NAMESPACE STD;

//	[문제] "메인.CPP"의 내용 중에 소문자를 모두 대문자로 바꿔 "메인 대문자.CPP"에 저장하라

//---------
INT MAIN() 
//---------
{
	IFSTREAM IN{ "MAIN.CPP" };
	IF (!IN)
		RETURN 20250325;

	OFSTREAM OUT{ "메인 대문자.CPP" };

	TRANSFORM(ISTREAMBUF_ITERATOR<CHAR>{IN}, {}, OSTREAMBUF_ITERATOR<CHAR>{OUT},
		[](CHAR C) {RETURN TOUPPER(C); });

	SAVE("MAIN.CPP");
}