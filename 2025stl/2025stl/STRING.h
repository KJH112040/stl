//----------------------------------------------------------------------------------
//	STRING.h - std::string과 유사한 클래스이다
//			   STL의 container로 동작할 수 있게 코딩해 나간다
//																	2025.4.8 시작
//----------------------------------------------------------------------------------
#pragma once
#include<memory>
#include<iostream>

class STRING {
public:
	STRING();						// 2025.04.08
	~STRING();								// 2025.04.08
											// 관찰을 위해 어쩔 수 없이

	STRING(const char* s);

	//	복사생성과 복사할당
	STRING(const STRING&);					// 2025.04.08
	STRING& operator=(const STRING&);		// 2025.04.08

	//	이동생성과 이동할당

	size_t size() const;

private:
	size_t len{};
	std::unique_ptr<char[]> p{};
	size_t id;									// 2025.04.08

	friend std::ostream& operator<<(std::ostream& os, const STRING& str);

	static size_t gid;						// 2025.04.08
};