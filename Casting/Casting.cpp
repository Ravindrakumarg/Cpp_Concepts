// Casting.cpp : Defines the entry point for the console application.

#include "stdafx.h"
#include "Casting.h"

/* IMPLiCIT CAST
 * Implicit conversions are automatically performed when a value is copied to a compatible type. 
   For example:
 * int a;
 * short b;
 * b = a
 */

class A
{
};

class B
{
public:
	explicit B(const A& aa){}

	B& operator=(const A& aa)
	{	return *this;	}

	operator A()
	{	return A();	}
};

void fn(B x){}

int _tmain(int argc, _TCHAR* argv[])
{
	A aa;
	B bb(aa);
	bb = aa;
	aa = bb;

//	fn(aa);				// while using explicit keywork we can not do B = A we need to do B(A)
	fn(bb);				// it will work fine

	dynamic_main();

	return 0;
}