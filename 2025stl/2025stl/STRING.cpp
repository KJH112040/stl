//----------------------------------------------------------------------------------
//	STRING.cpp - std::string과 유사한 클래스이다
//				 STL의 container로 동작할 수 있게 코딩해 나간다
//																	2025.4.8 시작
//----------------------------------------------------------------------------------
#include<iostream>
#include<memory>
#include<print>
#include"STRING.h"

// 관찰을 제어하기 위한 변수 추가				// 2025.04.08
bool 관찰{ false };					// 2025.04.08

STRING::STRING()							// 2025.04.08
	: id{++gid}
{
	if(관찰){
		std::println("[{:8}] {:16}, 자원수:{:<10}, 메모리:{:<12}, 자원메모리:{:<12}",
			id, "디폴트생성", len, (void*)this, (void*)p.get());
	}
}

STRING::~STRING()								// 2025.04.08
{
	if (관찰) {
		std::println("[{:8}] {:16}, 자원수:{:<10}, 메모리:{:<12}, 자원메모리:{:<12}",
			id, "소멸자", len, (void*)this, (void*)p.get());
	}
}

STRING::STRING(const char* s) 
	:id{++gid},len {	strlen(s)}
{
	p.reset();
	p = std::make_unique<char[]>(len);
	memcpy(p.get(), s, len);

	if (관찰) {
		std::println("[{:8}] {:16}, 자원수:{:<10}, 메모리:{:<12}, 자원메모리:{:<12}",
			id, "생성자(char*)", len, (void*)this, (void*)p.get());
	}
};

STRING::STRING(const STRING& other)			// 2025.04.08
	:id{ ++gid }, len{ other.len }		// 여기에 두 번째 인자를 넣게 되면, 순서가 보장되지 않음
{
	p = std::make_unique<char[]>(len);
	memcpy(p.get(), other.p.get(), len);

	if (관찰) {
		std::println("[{:8}] {:16}, 자원수:{:<10}, 메모리:{:<12}, 자원메모리:{:<12}",
			id, "복사생성자", len, (void*)this, (void*)p.get());
	}
}

STRING& STRING::operator=(const STRING& other)	// 2025.04.08
{
	if (this == &other)
		return *this;

	len = other.len;
	p.release();								// p.reset()과 다른 점을 공부하자
	p = std::make_unique<char[]>(len);
	memcpy(p.get(), other.p.get(), len);

	if (관찰) {
		std::println("[{:8}] {:16}, 자원수:{:<10}, 메모리:{:<12}, 자원메모리:{:<12}",
			id, "복사할당연산자", len, (void*)this, (void*)p.get());
	}

	return *this;
}

size_t STRING::size() const 
{
	return len;
}

std::ostream& operator<<(std::ostream& os, const STRING& str) 
{
	for (int i = 0; i < str.len; ++i)
		os << str.p[i];
	return os;
}

size_t STRING::gid{};						// 2025.04.0