#include <iostream>
#include "string.h"
class A
{
	char* str;
public:
	A() = default;
	A(const char* ptr)
	{
//		size_t length = std::strlen(ptr);
//		str = new char(length + 1);
//		strcpy_s(str, sizeof(str), ptr);
	}
	void display()
	{
		std::cout << "str:" << str << std::endl;
	}
};

int main()
{
	A a = { "hello" };
	a.display();

	getc(stdin);
	return 0;
}