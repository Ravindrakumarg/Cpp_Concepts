/*
 * Main class
 */

#include "iostream"

#ifndef __MAIN_SUBJECT_H__
#define __MAIN_SUBJECT_H__

class CRect
{
private:
	int __x, __y;
public:
	CRect ():__x(0), __y(0)
	{
	}

	CRect (int x, int y): __x(x), __y(y)
	{
	}

	~CRect(){};
	void Display ();
};

void CRect :: Display ()
{
	std::cout << "Rectangle x="<<__x<<" y="<<__y<<std::endl;
}

#endif  //__MAIN_SUBJECT_H__