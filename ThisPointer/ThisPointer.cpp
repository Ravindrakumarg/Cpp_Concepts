#include "stdafx.h"
#include <iostream>

// This pointer never point to a static fuction or static member variable
// static int fun();
// this->fun() -----------> will give a compilation error

// This pointer is a const pointer so
// this = class_obj-----------> will give a compilation error

// 'This' pointer should not be deleted. It is like deleting the self reference. It will throw exception

class Test
{
private:
	int a;
public:
	Test(){a=0;}
	void Distroy()
	{
		delete this;
	}
	void print()
	{
		std::cout << "a="<<a;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	Test t;
	t.Distroy();
	t.print();
	return 0;
}