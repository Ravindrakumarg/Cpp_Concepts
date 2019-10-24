// explicitly_dest_const.cpp : Defines the entry point for the console application.

#include "stdafx.h"
#include <iostream>

using namespace std;

/* we can explicitliy call the constructor and destructor
   calling the explicit constructor ( Test(); ) with call constructor and dest from same line
   calling the explicit dest ( t.~Test(); ) will call destructor of current object 
   but even after calling explicit constructor as object is going out of scope dest will get called */ 

class Test
{
public:
	int *a;
public:
	Test()
	{
		a = new int();
		*a = 10;
		cout << "test constructor" << endl;
	}
	~Test()
	{
		delete a;
		a = NULL;
		cout << "test destructor" << endl;
	}
	Test(Test& t)
	{
		a = new int();
		*a = *t.a;
		cout << "copy constructor" << endl;
	}
	friend void fun(Test t);
};

void fun(Test t)
{
	t.~Test();
}

int _tmain(int argc, _TCHAR* argv[])
{
	Test();			// this will call const and dest of Test class
	{
		Test t, t1;
		fun(t);
		t.~Test();	// This will call the dest of t
	}				// as t is going of scope here so dest will get called again.
	getchar();
	return 0;
}