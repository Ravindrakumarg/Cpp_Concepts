// TemplateExample.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "TemplateExample.h"

/*
 * making the template for only one method Maximum
 */
template <typename T>
T Maximum(T const &a, T const &b)
{
	return a>b?a:b;
}

template <typename T>
T minimum(T a, T b)
{
	return a<b?a:b;
}

int _tmain(int argc, _TCHAR* argv[])
{
	int a = 10;
	int b = 20;

	std::cout << "Maximum number:" << Maximum(a, b) << std::endl;
	
	double aF = 10.30;
	double bF = 10.20;

	std::cout << "Maximum number:" << Maximum(aF, bF) << std::endl;

	int diff = minimum(10, 20);

	MAX_MIN <int> m;
	m.initialize('A', 'B');
	std::cout << m.getMaximumNumber();

	return 0;
}