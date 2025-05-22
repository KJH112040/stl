//----------------------------------------------------------------------------------
//	STRING.cpp - std::string과 유사한 클래스이다
//				 STL의 container로 동작할 수 있게 코딩해 나간다
//																	2025.4.8 시작
//	2025. 4.
//	2025. 5. 1	>> 연산자
//	2025. 5. 13	begin(), end()
//	2025. 5. 22 <=> 연산자
//	2025. 5. 22 std::less 특수화?
//----------------------------------------------------------------------------------
#include<iostream>
#include<memory>
#include<print>
#include<algorithm>
#include<string>
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

//	이동생성과 이동할당연산자				// 2025.04.10
STRING::STRING(STRING&& other)				// && -> rvalue reference
	: id{ ++gid }, len{other.len}
{
	p.reset(other.p.release());

	if (관찰) {
		std::println("[{:8}] {:16}, 자원수:{:<10}, 메모리:{:<12}, 자원메모리:{:<12}",
			id, "이동생성자", len, (void*)this, (void*)p.get());
	}
}

STRING& STRING::operator=(STRING&& other)
{
	if (this == &other)
		return *this;

	len = other.len;
	p.release();
	p.reset(other.p.release());

	other.len = 0;

	if (관찰) {
		std::println("[{:8}] {:16}, 자원수:{:<10}, 메모리:{:<12}, 자원메모리:{:<12}",
			id, "이동할당연산자", len, (void*)this, (void*)p.get());
	}

	return *this;
}

// 2025. 04. 22 관계연산자들
//bool STRING::operator==(const STRING& rhs) const
//{
//	//if (len != rhs.len)
//	//	return false;
//	return std::equal(&p[0], &p[len], &rhs.p[0], &rhs.p[rhs.len]);
//}
//
//bool STRING::operator<(const STRING& rhs) const				// 2025.05.08
//{
//	return std::lexicographical_compare(p.get(), p.get() + len,
//		rhs.p.get(), rhs.p.get() + rhs.len);
//}

size_t STRING::size() const 
{
	return len;
}

//	begin(), end()														2025.5.13
STRING_Iterator STRING::begin()const
{
	return p.get();			// return &p[0];
}
STRING_Iterator STRING::end()const
{
	return p.get() + len;	// return &p[len];
}

STRING_Reverse_Iterator STRING::rbegin()const
{
	return STRING_Reverse_Iterator{ p.get() + len };
}
STRING_Reverse_Iterator STRING::rend()const
{
	return STRING_Reverse_Iterator{ p.get() };
}

std::ostream& operator<<(std::ostream& os, const STRING& str) 
{
	for (int i = 0; i < str.len; ++i)
		os << str.p[i];
	return os;
}

// 2025. 5. 1
std::istream& operator>>(std::istream& is, STRING& str)
{
	std::string s;
	is >> s;
	str.len = s.length();
	str.p.release();
	str.p = std::make_unique<char[]>(str.len);
	memcpy((char*)str.p.get(), s.data(), str.len);
	return is;
}

size_t STRING::gid{};						// 2025.04.0