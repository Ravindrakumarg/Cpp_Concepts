#include "stdafx.h"
#include <iostream>

 /* A base class pointer can point to a derived class object, 
    but we can only access base class member or virtual functions 
	using the base class pointer.
 */
class Base
{
public:
	int b = 4;
	void show()
	{
		std::cout << "in base b=" << b<< std::endl;
	}
	void show(int a)
	{
		std::cout << "in base int";
	}
};

class Drived : public Base						// If a derived class writes its own method,
												// then all functions of base class with same name become hidden, 
{												// even if signaures of base class functions are different. In the above 
public:											// question, when show() is rewritten in Derived, it hides both show() and show(int) of base class.
	int d = 10;
	void show()
	{
		std::cout << "in drived b="<<b<<" "<<"d="<<d<<std::endl;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	Drived dd;					//Normal Case //static linking - linked with drived show function at the compile time.
	dd.show();

	Base *B;
	Base b;

	B = &b;						// Normal Case
	B->b = 100;					// base class pointing is pointing to base class object so, normal case.
	B->show();

	Drived d;

	B = &d;
	B->b = 500;
	((Drived*)B)->d = 700;		//type cast //else B->d will not work.
	B->show();

	Drived *D;
	D = &d;						// Normal Case
	D->d = 200;
	D->b = 300;
	D->show();

	D =(Drived*) &b;
	D->show();

	getchar();
	return 0;
}