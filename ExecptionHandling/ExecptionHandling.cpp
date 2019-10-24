// ExecptionHandling.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

double division(int a, int b)
{
   if( b == 0 )
   {
      throw "Division by zero condition!";
   }
   int c = a/b;
   return (a*b);
}


int _tmain(int argc, _TCHAR* argv[])
{
	int x = 50;
    int y = 0;
    double z = 0;
 
	int arr[2] = {2, 4};
	cout << arr[-1]<<endl;
	arr[-1] = 100;
	cout << arr[-1]<<endl;
	cout << &arr[-1]<<" "<< &arr <<" "<<&arr[1]<<" "<<&arr[2]<<" "<< &arr[3]<<endl;
	cout << arr[3]<<endl;

	try
	{
		try
		{
			 z = division(x, y);
			 z = x/y;
			 cout << z << endl;
		}
		catch (exception e)
		{
			cerr << "actual try-catch block"<< endl;
		}
		catch (const char* msg)
		{
			cerr << "Catch the errer in inner block: " << msg<<endl;	//It will got catch in inner try-catch block only
		}
    }
	catch (const char* msg) 
	{
		cerr << "Catch the error:" << msg << endl;
    }

	try
	{
		FILE *fp = fopen("hello.txt", "r");
		fputs("hello", fp);
	}
	catch(exception ex)
	{

	}

	getchar();
    return 0;
}

