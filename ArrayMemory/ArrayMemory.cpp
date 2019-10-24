// ArrayMemory.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

int main()
{
	char *_name;
	_name = new char[10];
	
	delete []_name;

	int *ptr = nullptr;
	delete ptr;

	getc(stdin);

	return 0;
}
