
// is that const char* is same as std::string
// diffirence between const char* to char*
// diff bet <string>, "string", "string.h"
#include <iostream>

void TokenWord(const char*);
void TokenName(char*);
void ReplaceName(const char*);

int main()
{
	TokenWord("server:data:comp");

	char name[] = "tally server 9";
	TokenName(name);

//	const char* name1 = "tally server 9";	//using this will through write access violation."
	char name1[] = "tally server 9";
	ReplaceName(name1);

	getchar();
	return 0;
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