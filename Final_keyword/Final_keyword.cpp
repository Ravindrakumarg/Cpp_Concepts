/*
*******1st Use**********
Sometimes you don’t want to allow derived class to override the base class’ 
virtual function. C++ 11 allows built-in facility to prevent overriding of 
virtual function using final specifier.
*/

/*
********2nd Use*********
final specifier in C++ 11 can also be used to prevent inheritance of class / struct. 
If a class or struct is marked as final then it becomes non inheritable and it cannot 
be used as base class/struct.
The following program shows use of final specifier to make class non inheritable:
*/

#include "stdafx.h"
#include <iostream>

using namespace std;

class Base
{
public:
	Base(){}
	~Base(){}

	virtual void display() //final
	{ cout << "Base display"<<endl; }
};

class Drived : public Base
{
public:
	void display()
	{ cout << "drived display" << endl; }
};

int _tmain(int argc, _TCHAR* argv[])
{
	Base b;
	Drived d;
	b = d;
	b.display();

	getchar();
	return 0;
}