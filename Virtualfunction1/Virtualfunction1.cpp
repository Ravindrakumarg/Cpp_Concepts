#include "stdafx.h"
#include <iostream>

class CBase
{
private:
	int a;
public:
	CBase()
	{
		a = 10;
	}
	void Display1 ()
	{
		std::cout << "Base display1 =" <<a<<std::endl;
	}
	void Display2 ()
	{
		std::cout << "Base Display2 =" << a << std::endl;
	}
	virtual void Display()
	{
		Display1();
		Display2();
	}
};
class CDrived1 : public CBase
{
private:
	int b;
public:
	CDrived1()
	{
		b = 20;
	}
	void Display1 ()
	{
		std::cout << "Drived1 display1 =" <<b<<std::endl;
	}
	void Display2 ()
	{
		std::cout << "Drived1 display2 =" <<b<<std::endl;
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	CBase b;
	b.Display1();
	b.Display2();
	b.Display();

	CDrived1 d;
	d.Display1();
	d.Display2();
	d.Display();

	b = d;
	b.Display1();
	b.Display2();
	b.Display();

	CBase *b1;
	b1 = &b;
	b1->Display1();
	b1->Display2();
	b1->Display();

	b1 = &d;
	b1->Display1();
	b1->Display2();
	b1->Display();

	getchar();
	return 0;
}