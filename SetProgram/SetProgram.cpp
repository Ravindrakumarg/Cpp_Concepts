// SetProgram.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <set>
#include <iostream>
#include <map>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	map<int, float> mymap;
	mymap[1]=2.0;
	mymap[2]=3.4;
	mymap[1]=3.0;

	float f = mymap[4];						// Accessing worng key will return 0 as a value
	cout <<"\n value=" << f;

	map<int, float>::iterator it;

	for(it=mymap.begin(); it != mymap.end(); it++)
	{
		cout << "\n key="<<it->first <<" value= " << it->second;
	}
	cout << "\n key="<<it->first <<" value= " << it->second;

	getchar();
	return 0;
}

#if 0
	std::set<int, int> myset;
	myset.insert(1, 10);

	std::set<int, int>::iterator it;
	for(it=myset.begin(); it!=myset.end();it++)
	{
		std::cout << "\n value="<< *it;
	}


	getchar();
	return 0;
}
#endif

