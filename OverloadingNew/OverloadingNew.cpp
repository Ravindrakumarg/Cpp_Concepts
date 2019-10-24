
#include "stdafx.h"
#include "iostream"

void* operator new(size_t size)
{
	void *p = malloc(size);
	return p;
}

void operator delete(void * ptr)
{
	free(ptr);
}

int main()
{
	int* a = new int[4];
	std::cout << "Value of a:" << *a << std::endl;

	delete a;
//	a = nullptr;
	delete a;

    return 0;
}