#include <iostream>

int main()
{
	auto funptr = [](const char* str) 
	{
		std::cout << str << std::endl;
	};

	funptr("hello world");

	getc(stdin);
}