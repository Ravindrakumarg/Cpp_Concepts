#ifndef __DISTRUCTOR__
#define __DISTRUCTOR__

#include <iostream>

class CVirtualDistructor
{
public:
	CVirtualDistructor()
	{
		std::cout << "base class constructor\n";
	}
	virtual ~CVirtualDistructor() = 0;				// if we declare destructor as pure virtual distructor		\
	//{												// then we will not able to create the object of base class \
	//	std::cout << "base class distructor\n";		// pure virtual destructor still be need a body because this
	//}												// this method can not be overridden.
};
class CVirtualDistructor1
{
public:
	CVirtualDistructor1()
	{
		std::cout << "base class constructor\n";
	}

	virtual ~CVirtualDistructor1() = 0;				// if we declare destructor as pure virtual distructor		\
	//{												// then we will not able to create the object of base class \
	//	std::cout << "base class distructor\n";
	//}
};

CVirtualDistructor :: ~CVirtualDistructor()
{
	std::cout << "base class distructor\n";
}

class A : public CVirtualDistructor
{
public:
	A()
	{
		std::cout << "Drived class constructor \n";
	}
	~A()
	{
		std::cout << "drived class distructor \n";
	}
};
#endif