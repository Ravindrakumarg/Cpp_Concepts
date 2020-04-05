
// is that const char* is same as std::string
// diffirence between const char* to char*
// diff bet <string>, "string", "string.h"
#include <iostream>


void TokenWord(const char*);
void TokenName(char*);
void ReplaceName(const char*);
void CheckConst();
void CheckDelete();

int main()
{
	TokenWord("server:data:comp");

	char name[] = "tally server 9";	// here name is a pointer pointing to a const char array or const char*
	TokenName(name);

//	const char* name1 = "tally server 9";	//using this will through write access violation."
	char name1[] = "tally server 9";
	ReplaceName(name1);
	name1[0] = 't';

	CheckConst();
	CheckDelete();
	
	char *ptr = new char[20];

	getchar();
	return 0;
}

void CheckConst()
{
	char const * p1 = "hello";	//p is normal pointer which is pointing to "const char *"
	const char * p11 = "hello";	// this is same as "char const*"
	p1 = p11;						// so this is valid;

	const char * const p2 = "hello"; //p1 is const pointer type pointing to "const char *"
	const char * p21 = "hi";
//	p2 = p21;						// as p2 is const pointer, it value cal not be changed. compilation error.

	char * const p3 = nullptr;
	const char* p31 = "hi";
//	p3 = p31;						// this one will again through error as p3 is a const pointer pointing to char*;
}

void CheckDelete()
{
	const char * af = "aje";	// here memory is allocated on stack not on heap
//	delete af;					// so, this line will throw exception

	char *abc = new char[10];
	delete abc;					// here memory is allocated on heap so followup delete will work
}

void ReplaceName(const char* name)
{
	char *sep = (char*)name;
	*sep = 'T';
}

void TokenName(char * name)
{
	while (1)
	{
		if (*name == '\0')
			break;
		if (*name == ' ')
			std::cout << std::endl;
		else
			std::cout << *name;

		name++;
	}
}

void TokenWord(const char* path)
{
	while (1)
	{
		if (*path == '\0')
			break;
		if (*path == ':')
		{
			std::cout << std::endl;
		}
		else
			std::cout << *path;

		path++;
	}
	std::cout << std::endl;
}