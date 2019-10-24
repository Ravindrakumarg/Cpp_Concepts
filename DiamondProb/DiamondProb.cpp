#include "stdafx.h"
#include <iostream>

using namespace std;

/* virtual inheritence allow only one copy of grandparent class to lowest class irrespective of how many 
   level of inheritence */

class A
{
	int _a;
public:
	A()
	{ cout << "A constructor" << "\n"; _a = 0; }
	A(int a)
	{ cout << "A(int) constructor" << "\n"; _a = a; }
	~A()
	{ cout << "~A distructor" << "\n"; }
	void Display()
	{ cout << "_a=" << _a << "\n"; }
};

class B : virtual public A
{
	int _b;
public:
	B()
	{ cout << "B constructor" << "\n"; _b=0; }
	B(int a): A(50)
	{ cout << "B(int) constructor" << "\n"; _b=a; }
	~B()
	{ cout << "~B distructor" << "\n"; }
	virtual void Display()
	{ cout << "_b=" << _b << "\n"; }
};

class C : virtual public A
{
	int _c;
public:
	C()
	{ cout << "C constructor" << "\n"; _c=0; }
	C(int a):A(40)
	{ cout << "C(int) constructor" << "\n"; _c=a; }
	~C()
	{ cout << "~C distructor" << "\n"; }
	virtual void Display()
	{ cout << "_c=" << _c << "\n"; }
};

class D : public B, public C
{
	int _d;
public:
	D()
	{ cout << "D constructor" << "\n"; _d=0; }
	D(int a):B(10), C(20) // if we dont call parametrized constructor here then 
	{ cout << "D(int) constructor" << "\n"; _d=a;}			// it will call the default constructor
	~D()
	{ cout << "~D distructor" << "\n"; }
	virtual void Display()
	{ cout << "_d=" << _d << "\n"; }
};

int _tmain(int argc, _TCHAR* argv[])
{
	{
	D d(1);

	d.Display();
	cout << "D:" << sizeof(D) << endl;

	d.B::Display();
	d.C::Display();
	d.A::Display();
	}
	getchar();

	return 0;
}