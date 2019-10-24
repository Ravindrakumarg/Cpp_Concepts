// HybridInheritance1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

/*
 if a class object is not dynamic so it will call only their member function even it is inherited from base
 polimorphism will come in the picture only when we will use dynamic object
*/

class CBase
{
public:
	virtual void Display()
	{
		std::cout << "Base Display"<<std::endl;
	}
};

class CDrived1 : public CBase
{
public:
	virtual void Display()
	{
		std::cout << "Drived1 Display"<<std::endl;
	}
};

class CDrived2 : public CBase
{
public:
	virtual void Display()
	{
		std::cout << "Drived2 Display"<<std::endl;
	}
};

class CChild : public CDrived1, public CDrived2
{
public:
	void Display()
	{
		std::cout << "child Display"<<std::endl;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	CBase base;						//all statically created objects will call their version of display function
	base.Display();

	CDrived1 d1;
	d1.Display();

	CDrived2 d2;
	d2.Display();

	CChild c;
	c.Display();


	CBase *b;						//if base class function is virtual then it will call assigned object method otherwise base class function
	b = &d1;
	b->Display();

	b = &(CDrived2)c;
	b->Display();

	return 0;
}