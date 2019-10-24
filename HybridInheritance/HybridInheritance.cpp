// HybridInheritance.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"


class Sports
{
private:
	int __sports_cred;
public:
	void allocate_sport_mark(int mark)
	{
		__sports_cred = mark;
	}
	int display_mark()
	{
		std::cout << "Sport marks: " << __sports_cred <<"\n";
		return __sports_cred;
	}
};

class Marks : public Sports
{
private:
	int __sub1;
	int __sub2;
public:
	void allocate_subject_marks(int m1, int m2)
	{
		__sub1 = m1;
		__sub2 = m2;
	}
	int display_mark()
	{
		std::cout << "subjects marks: " << __sub1 << "  "<< __sub2 <<"\n";
		return (__sub1+__sub2);
	}
};

class StudentInfo : public Marks
{
private:
	int			__rool_number;
	std::string	__name;
public:
	void allocate_student_info( int _trol, std::string _sname)
	{
		__rool_number = _trol;
		__name		  = _sname;
	}

	void display_stu_info ()
	{
		std::cout << "\n student info\n";
		printf ("Name: %s\n", __name);
		std::cout << "Roll number: "<< __rool_number <<"\n";
		std::cout << "Total Mark:"; total_marks();
	}
	void total_marks();
};

void StudentInfo :: total_marks()
{
	//display_stu_info();
	int t1 = Marks::display_mark();
	int t2 = Sports::display_mark();

	std::cout <<" Total marks:" << (t1+t2) <<"\n";
}

int _tmain(int argc, _TCHAR* argv[])
{
	StudentInfo si;
	si.allocate_student_info ( 1111, "Ravindra");
	si.allocate_sport_mark (86);
	si.allocate_subject_marks (60, 70);

	si.display_stu_info();
	return 0;
}
 