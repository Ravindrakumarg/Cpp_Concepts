// OperatorOverloading.cpp : Defines the entry point for the console application.
#include "stdafx.h"
#include "iostream"

class Vector
{
private:
	int x_axis;
	int y_axis;
public:
	Vector(){}
	Vector (int x, int y)
	{
		x_axis = x;
		y_axis = y;
	}
	void display ()
	{
		std::cout << "\nvector is:"<<x_axis<<"+"<<y_axis<<"x\n";
	}
	Vector operator+(Vector temp);
	void operator-();
	void operator+();
	void operator++(int);
	void operator++();
	friend std::ostream& operator << (std::ostream& out, const Vector& v);
	friend std::istream& operator >> (std::istream& in, Vector& v);
};

Vector Vector:: operator + (Vector v)		// If in operator overloading two object would be there then it will take 
{											// left one as reference varaible for calling and other as argument.
	std::cout << "\ndbg:"<<this->x_axis<<"+"<<this->y_axis<<"x\n";
	std::cout << "\ndbg:"<<v.x_axis<<"+"<<v.y_axis<<"x\n";
	return ( Vector ((x_axis+v.x_axis), (y_axis+v.y_axis)));
}

void Vector ::operator- ()					// If in operator overloading only one argument will be there then it will 
{											// take that one as reference no metter object is in left or right
	x_axis = -x_axis;
	y_axis = -y_axis;
}

void Vector :: operator+()
{
	x_axis = x_axis;
	y_axis = y_axis;
}

void Vector :: operator++(int)			// post increment should be extra one argument as int to categories from pre increment
{
	this->x_axis++;
	this->y_axis++;
}

void Vector :: operator++()				// pre increment
{
	this->x_axis++;
	this->y_axis++;
}

std::ostream& operator << (std::ostream& out, const Vector& v)
{
	out << "\nvector is:" << v.x_axis << "+" << v.y_axis << "x\n";
	return out;
}

std::istream& operator >> (std::istream& in, Vector& v)
{
	std::cout << "please enter two value: ";
	in >> v.x_axis >> v.y_axis;
	return in;
}

int _tmain(int argc, _TCHAR* argv[])
{
	Vector v1(2, 3), v2(4, 5);

	std::cout << v1 << v2;
	std::cin >> v1 >> v2;
	std::cout << v1;

	v1.display();
	v2.display();

	-v1;
	v1.display();

	+v1;
	v1.display();

	-v1;
	v1.display();

	Vector v3;
	v3 = v1 + v2;
	v3.display();

	v1++;
	v1.display();

	++v1;
	v1.display();

	return 0;
}