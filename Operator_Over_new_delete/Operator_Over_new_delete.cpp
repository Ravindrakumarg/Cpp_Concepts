
#include "stdafx.h"
#include <iostream>

/* new call is getting split in to two part. FIrst is memory allocation(melloc) then initialising the memory */
/* in the same way deleting memory is again splitting into two part first is unintializing the memory and then deallocation of memory */
/* new is first calling malloc internally for memory allocation then calling constuctor for intializing that memory */
/* same way delete is first calling the destructor to uninitialize the memory and then calling free to deallocate the memory */
/* Even after creating the memory with new we can call free on that it will deallocate the memory but woun't call the destructor. */

using namespace std;

class Test
{
private:
	int _x;
	int _y;
public:
	Test() : _x(0), _y(0)
	{
		cout << "default constructor called" << endl;
	}
	Test(int x, int y) :_x(x), _y(y)
	{
		cout << "constructor called"<<endl;
	}
	~Test()
	{
		cout << "destructor called" << endl;
	}

	void* operator new (size_t size)
	{
		void* storage = malloc(size);
		cout << "new called"<<endl;
		return storage;
	}
	void operator delete(void* storage)
	{
		cout << "delete called"<<endl;
		delete storage;
	}
	void* operator new[](size_t size)
	{
		void *memory = malloc(size);
		cout << "new[] called" << endl;
		return memory;
	}
	void operator delete[](void* storage)
	{
		cout << "delete[] called" << endl;
	}
	void display()
	{
		cout << "x=" << _x << ",y=" << _y << endl;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	Test *t1 = new Test(2, 4);
	t1->display();
//	free(t1);		// calling of free is fine.. it will deallocate the memory but destructor woun't get called. 
					// Object woun't be properly called.
	delete t1;

//	Test *t11 = (Test*)malloc(sizeof(Test)); // malloc will also allocate memory but not initialization
//	t11->display();

	Test *t2 = new Test[5];
	delete[] t2;

	getchar();

	return 0;
}