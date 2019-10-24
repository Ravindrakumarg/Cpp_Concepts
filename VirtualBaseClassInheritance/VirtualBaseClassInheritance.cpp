#include "stdafx.h"
#include "iostream"

class StudentInfo
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
	}
};


class Sports : virtual public StudentInfo
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

class Marks : virtual public StudentInfo
{
private:
	int __sub1;
	int __sub2;
public:
	void allocate_marks(int m1, int m2)
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

class Result : public Marks, public Sports
{
public:
	void totalmarks();
};

void Result :: totalmarks()
{
	int total_sum = 0;
	display_stu_info();
	total_sum += Marks::display_mark();
	total_sum += Sports::display_mark();
	std::cout <<"Total Marks: " << total_sum;
}

int _tmain(int argc, _TCHAR* argv[])
{
	Result _res;
	_res.allocate_student_info (111, "ravindra");
	
	_res.allocate_sport_mark(30);
	_res.allocate_marks (40, 20);

	_res.totalmarks();
	return 0;
}