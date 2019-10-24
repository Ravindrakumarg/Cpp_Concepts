// DeepShollowCopy.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;
/* Deep and Shollow copy constructor concept come in picture when we have dynamic variable is 
 * class and copy constructor just initializing the pointer variable with same reference so that 
 * two or more object of that class dynamic variable refer to same address so, deleting a single 
 * object of that class will delete that reference and other object member will be dangling pointer.
 */

/* So, to over come with this problem we are taking the reference of object and creating saperate
 * memory block for dynamic member of other object.
 * More detail see the Example...........
 */
class test
{
private:
	int*		_a;
	char		_ch;
	std::string	_str;

public:
	test(char ch, std::string str)
	{
		_a = new int;
		*_a = 100;
		_ch = ch;
		_str = str;
	}

	void display ()
	{
		std::cout << "a="<< *_a <<" &a="<< &_a <<" ch=" << _ch << " str=" << std::endl;
	}

	test(test &t)
	{
		_a = new int;
		_a = t._a;
		_ch = t._ch;
		_str = t._str;
	}

	test(test *t)
	{
		_a = new int;
		_a = t->_a;
		_ch = t->_ch;
		_str = t->_str;
	}

	test (test **t)
	{
		_a = new int;
		_a = (*t)->_a;
		_ch = (*t)->_ch;
		_str = (*t)->_str;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	test *t = new test('y', "my cat");
	t->display();

	test t1(&t);
	t1.display();

	test t2('z', "my dog");

	test t3(t2);
	t3.display();

	test t4(&t2);
	t4.display();

	getchar();
	return 0;
}