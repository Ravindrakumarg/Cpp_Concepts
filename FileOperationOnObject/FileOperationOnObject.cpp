#include "stdafx.h"
#include "fstream"
#include "iostream"

using namespace std;

#define FILE_NAME	"d:\\file_operation1.txt"

class Employee
{
	char *name;
	float salary;
	float age;

public:
	Employee()
	{
		name = new char(20);
		memset(name, '\0', sizeof(name));
		salary = 0;
		age = 0;
	}

	void get_employee_data()
	{
		cout << "\nEnter employee name:";
		name = new char(20);
		cin >> name;
		cout << "\nEnter employee salary:";
		cin >> salary;
		cout << "\nEnter employee age:";
		cin >> age;
	}
	void print_employee_data()
	{
		cout << "\nEmployee name:" << name;
		cout << "\nEmployee salary:" << salary;
		cout << "\nEmployee age:" << age;
	}
};

int main()
{
	Employee emp[3];
	ofstream outfile(FILE_NAME);
	for (int i = 0; i < 3; i++)
	{
		emp[i].get_employee_data();
		outfile.write((char*)&emp[i], sizeof(emp));
	}

	outfile.close();

	Employee emp1[3];
	ifstream infile(FILE_NAME);
	cout << "\n\nOutput:\n";
	for (int i = 0; i < 3; i++)
	{
		infile.read((char*)&emp1[i], sizeof(emp1));
		emp1[i].print_employee_data();
		cout << endl;
	}
	infile.close();

    return 0;
}