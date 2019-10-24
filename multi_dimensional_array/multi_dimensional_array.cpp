// multi_dimensional_array.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

int _tmain(int argc, _TCHAR* argv[])
{
	int s[][2] = {
					{1, 2},
					{3, 4},
					{5, 6},
					{7, 8}
				}; 

	int (*p)[2];
	int* ptr;

	for(int j=0; j<4; j++)
	{
		p = &s[j];
		int* ptr = (int*)p;
		for (int i=0; i<=1; i++)
		{
			std::cout << "value="<<*ptr;
			ptr++;
		}
		std::cout << std::endl;
	}
	return 0;
}