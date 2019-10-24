#include "stdafx.h"
#include "iostream"

typedef int (*pt2function) (float, int);
typedef int (*pt2func) (bool, int (*pt2function(float, int)));

int fnptr_as_arg(bool b,int (*pt2function)(float, int))
{
	//pt2function = &plus;
	int result = (*pt2function)(10, 20);
	return result;
}

int target_function(float f, int i)
{
	return 10;
}

float plus(float arg1, float arg2)
{
	return (arg1+arg2);
}

float minus(float arg1, float arg2)
{
	return (arg1-arg2);
}

float (*GetPtr1(const char opCode))(float, float)
{
	if(opCode == '+')
		return &plus;
	else
		return &minus; // default if invalid operator was passed
}

int _tmain(int argc, _TCHAR* argv[])
{
	typedef float(*func)(float, float);
		//float(*func)(float, float) = minus;
		func f = minus;
	std::cout << f(10, 20);

	int result;
	pt2function fp;

	fp = &target_function;
	if (fp == &target_function)
		result = fp(1, 2);
	printf ("%d\n", result);

	result = fnptr_as_arg(false, &target_function);
	printf ("%d\n", result);

	//pt2func _fp;
	//_fp = &fnptr_as_arg;
	return 0;
}








#if 0
	typedef void (*funcPointer)(int, int);

	void add (int a, int b)
	{
		std::cout <<a<<"+"<<b<<"="<<a+b<<"\n";
	}

	void sub (int a, int b)
	{
		std::cout <<a<<"+"<<b<<"="<<a-b<<"\n";
	}

	int _tmain(int argc, _TCHAR* argv[])
	{
		funcPointer _fp;
		_fp = &add;
		_fp(2, 5);

		_fp = &sub;
		_fp(5, 2);

		return 0;
	}
#endif