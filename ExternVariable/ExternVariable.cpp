
#include "stdafx.h"
#include <iostream>

using namespace std;

extern int value;

void sum()
{
	int a = 10;
}

int _tmain(int argc, _TCHAR* argv[])
{
	cout << "value:" << value << endl;
	int a = 20;
	cout << "address a=" << &a << " a=" << a << endl;

	getchar();
	return 0;
}