// StructureClassSize.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <stdlib.h>
#include "StructureClassSize.h"

int _tmain(int argc, _TCHAR* argv[])
{
	std::cout << "size of bit structure=" << sizeof(Bit) << std::endl;

	A a{'a', 9, 'b'};
	std::cout << "size of structure=" << sizeof(a) << std::endl;

	STest t;
	std::cout << "size of structure=" << sizeof(t) << std::endl;
	std::cout << "f="<<sizeof(t.f) <<" i="<<sizeof(t.a)<<" c="<<sizeof(t.ch)<<std::endl;


	CTest ct;
	std::cout << "size of class=" << sizeof(ct) << std::endl;
	std::cout << "f="<<sizeof(ct.f) <<" i="<<sizeof(ct.a)<<" c="<<sizeof(ct.ch)<<std::endl;

	CDrived cd;
	std::cout << "size of class=" << sizeof(cd) << std::endl;
	std::cout << "f="<<sizeof(cd.f) <<" i="<<sizeof(cd.a)<<" c="<<sizeof(cd.ch)<<std::endl;

	CT c;
	std::cout << "ize of CT="<<sizeof(c)<<std::endl;

	getchar();
	return 0;
}