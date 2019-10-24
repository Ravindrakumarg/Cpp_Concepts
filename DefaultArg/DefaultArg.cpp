// DefaultArg.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

typedef const char* CSTRPTR;

// enable this will call string1 method
// void CheckString(CSTRPTR name, CSTRPTR address = nullptr, CSTRPTR info = nullptr);

// enable this will call string2 method
 void CheckString(CSTRPTR name); // ambigous call // declaration we can not add but defination we add, it will give warning

 int checkDefaultArg(int a, int b=0, int c=0)
{
	std::cout << "argument" << std::endl;
	return 0;
}

int main()
{
	checkDefaultArg(10, 16);
    std::cout << "Hello World!\n";

	CheckString("aaa");

	getc(stdin);
	return 0;
}

void CheckString(CSTRPTR name)
{
	std::cout << "string2" << std::endl;
}

void CheckString(CSTRPTR name, CSTRPTR address, CSTRPTR info)
{
	std::cout << "string1" << std::endl;
}

