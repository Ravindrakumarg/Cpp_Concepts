#ifndef __SIZEOF__
#define __SIZEOF__

// pragma pack will control the padding in structure
// without pragma below structure will have size 12 byte with pragma 1 it will be 6 byte
// push & pop is to control the range(how many structure should be go with that rule)
#pragma pack(push, 1)
struct A
{
	char c;
	int a;
	char c1;
};
#pragma pack(pop)

struct Bit
{
	int first		: 1;	// allocating 1 bit for first
	short second	: 8;	// allocating 8 bit for second
};

struct STest
{
	int a;
	char ch;
	float f;
};

class CTest
{
public:
	int a;
	char ch;
	float f;
};

class CDrived : public CTest
{
public:
	char ch;
};

class CT
{
public:
	CT()		{ std::cout << "in constructor"<<std::endl; }
	~CT()		{ std::cout << "in distructor"<<std::endl; }
};
#endif