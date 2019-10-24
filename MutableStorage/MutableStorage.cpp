
/*
The mutable storage class specifier in C++ (or use of mutable keyword in C++)
auto, register, static and extern are the storage class specifiers in C. typedef 
is also considered as a storage class specifier in C. C++ also supports all these 
storage class specifiers. In addition to this C++, adds one important storage class 
specifier whose name is mutable.


What is the need of mutable?
Sometimes there is requirement to modify one or more data members of class / struct 
through const function even though you don’t want the function to update other members 
of class / struct. This task can be easily performed by using mutable keyword. Consider
this example where use of mutable can be useful. Suppose you go to hotel and you give 
the order to waiter to bring some food dish. After giving order, you suddenly decide to 
change the order of food. Assume that hotel provides facility to change the ordered food 
and again take the order of new food within 10 minutes after giving the 1st order. After 
10 minutes order can’t be cancelled and old order can’t be replaced by new order. See the 
following code for details.


Result?
Closely observe the output of above program. The values of placedorder and bill data 
members are changed from const function because they are declared as mutable.

The keyword mutable is mainly used to allow a particular data member of const object 
to be modified. When we declare a function as const, the this pointer passed to function 
becomes const. Adding mutable to a variable allows a const pointer to change members.
mutable is particularly useful if most of the members should be constant but a few need 
to be updateable. Data members declared as mutable can be modified even though they are 
the part of object declared as const. You cannot use the mutable specifier with names 
declared as static or const, or reference.

*/

#include "stdafx.h"
#include <iostream>

using namespace std;

class Customer
{
private:
	char			_name[25];
	mutable char	_placeorder[25];
	int				_table_no;
	mutable float	_price;

public:
	Customer(char* name, char* order, int no, float price)
	{
		strcpy(_name, name);
		strcpy(_placeorder, order);
		_table_no = no;
		_price	= price;
	}

	void change_order(char *order, float price) const
	{
		strcpy(_placeorder, order);
		_price += price;
	}

	void display() const
	{
		cout << "name="<<_name<<endl;
		cout << "order name="<< _placeorder<<endl;
		cout << "table no="<< _table_no << endl;
		cout << "price=" << _price << endl << endl;
	}
};

int main()
{
	Customer const c("ravindra", "icecream", 3, 100);
	c.display();
	c.change_order("gulaab jamun", 200);
	c.display();

	getchar();
	return 0;
}


#if 0
class Test
{
public:
	int x;
	mutable int y;											// this varaible can be modified by const object also

	Test()
	{
		x = 4; y = 5;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
															// as t is a const object so mon mutable value will not be modified later.
	const Test t;											// so t.y =10 will work fine but
	cout << "x = "<<t.x<<" "<<"y="<<t.y<<endl;				// t.x = 10; will give error as we can't modified x modifier
	t.y = 10;
	cout << "x = "<<t.x<<" "<<"y="<<t.y<<endl;
	getchar();
	return 0;
}
#endif