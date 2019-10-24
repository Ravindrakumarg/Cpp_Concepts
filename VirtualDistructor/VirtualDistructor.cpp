#include "stdafx.h"
#include <iostream>
#include "VirtualDistructor.h"

int _tmain(int argc, _TCHAR* argv[])
{
	CVirtualDistructor *v ;//= new CVirtualDistructor();
	//delete v;

	A *a= new A();
	//delete a;				//	Drived *d = new Drived();
	v = a;					//	Base *b = d;
	delete v;				//	delete b;		//in this case distructor of drived class wount get called
							//	solution: is that base class ditructor need to be virtual
	getchar();
	return 0;
}