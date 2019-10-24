#include "stdafx.h"
#include "iostream"

class Data
{
private:
	int a;
public:
	void allocate_a(int temp)
	{
		a=temp;
	}
	int get_a() { return a;}
};

class Usage : public Data
{
private:
	int b;
public:
	void allocate_b(int temp)
	{
		b=temp;
	}
	void mul();
};

void Usage :: mul()
{
	int c = b * get_a();				//because a is private
	std :: cout << "Mul="<<c; 
}

// In a private inheritance public member of base class become private member of child class
class Usage1 : private Data	// because of private inheritance public member became private here
{
private:
	int b;
public:
	void allocate_ab(int x, int y)
	{
		allocate_a(x);					//calling the private member allocate_a() function
		b=y;
	}
	void mul();
};


void Usage1 :: mul()
{
	int c = b * get_a();
	std :: cout << "\nMul="<<c; 
}

int _tmain(int argc, _TCHAR* argv[])
{
	Usage user;
	user.allocate_a(10);
	user.allocate_b(20);
	user.mul();

	Usage1 user1;
	user1.allocate_ab(10, 20);
	user1.mul();
	return 0;
}