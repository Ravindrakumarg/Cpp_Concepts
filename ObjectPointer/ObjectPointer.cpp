// ObjectPointer.cpp : Defines the entry point for the console application.

#include "stdafx.h"
#include "iostream"
#include "string.h"

using namespace std;

class City
{
private:
	char *name;
public:
	City()
	{
		this->name = new char[1];
	}
	~City()
	{
		delete name;
		name = 0;
	}
	void allocatename();
	void displayname();
};

void City::allocatename()
{
	cout << "Enter the city name \n";
	char *local_name;
	local_name = new char[30];
	cin >> local_name;

	name = new char (strlen (local_name));
	strcpy(name, local_name);
}

void City :: displayname()
{
	cout << "City name:" << name <<"\n";
}

int _tmain(int argc, _TCHAR* argv[])
{
	City *ptr = new City();
	ptr->allocatename();
	ptr->displayname();
	return 0;
}