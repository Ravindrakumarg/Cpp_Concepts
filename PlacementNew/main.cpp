#include <iostream>
#include <new>
#include <string>

using namespace std;
/*placement new allows us to construct an object at a specific, preallocated memory address.*/
class Data
{
	int	  _a;
	char* _name;
public:
	Data() {}
	Data(int a, size_t size)
	{
		_a = a;
		_name = (char*)malloc(size);
		strcpy_s(_name, sizeof(_name), "hello");
	}
	~Data()
	{
		delete _name;
	}
};

char buffer2[100];		// preallocated memory

int main()
{
	char buffer1[200];	// preallocated memory
	Data *data = new(buffer1) Data();
	// delete data; // should not call delete on placement new 
					// this will call the destructor but memory of object will not be completely free

	int* arr = new(buffer2) int[10]; // same as int* arr = new int[10];

	data->~Data();	

	getchar();
}