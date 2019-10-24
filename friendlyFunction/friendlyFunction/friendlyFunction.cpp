// friendlyFunction.cpp : Defines the entry point for the console application.

#include "stdafx.h"
#include "iostream"
#include "stdio.h"

class Employee;		//forward declaration

class Sallary
{
private:
	int _sal_amount;

public:
	friend void get_salary(Sallary, Employee &);
	void put_salary()
	{
		printf ("Enter the amount:");
		std::cin >> _sal_amount;
	}
	void display_salary()
	{
		std::cout <<"Salary Stored:" <<_sal_amount<<"\n";
	}
};

class Employee
{
private:
	int _salary;
public:
	friend void get_salary(Sallary, Employee &);
	void display_salary()
	{
		std::cout <<"Salary Got:" <<_salary<<"\n";
	}
};

void get_salary( Sallary sal, Employee &emp)
{
	emp._salary = sal._sal_amount;
}

int _tmain(int argc, _TCHAR* argv[])
{
	Sallary sal;
	sal.put_salary();
	sal.display_salary();

	Employee emp;
	get_salary(sal, emp);
	emp.display_salary();

	return 0;
}