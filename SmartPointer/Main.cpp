// SmartPointer.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Polygon.h"
#include "Rectangle.h"
#include "SmartPointer.h"


int _tmain(int argc, _TCHAR* argv[])
{
	CSmartPointer<CRect> smt_pnt(new CRect(10, 12));
	smt_pnt->Display();

	{
		CSmartPointer<CRect> sm1 = smt_pnt;
		sm1->Display();

		CSmartPointer<CRect> sm2;
		sm2 = sm1;
		sm2->Display();
	}

	CRect *rect = new CRect(10, 12);
	rect->Display();

	std::cin.get();
	return 0;
}