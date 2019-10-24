// VaraibleArgument.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <stdarg.h>

using namespace std;

int get_max_num(int a,...);

int _tmain(int argc, _TCHAR* argv[])
{
	int max = get_max_num(10, 3, 7, 43 ,10, 8);
	cout << "Max num="<<max<<endl;
	return 0;
}

int get_max_num(int a, ...)
{
	int max = 0, i=0, num;
	va_list ptr;
	va_start(ptr, a);
//	max = va_arg(ptr, int);
	for(i=1;i<a;i++)
	{
		num = va_arg(ptr, int);
		if (max < num)
			max = num;
	}

	return max;
}
