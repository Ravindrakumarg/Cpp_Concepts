// Reference_variable.cpp : Defines the entry point for the console application.
//

/*************************************************************************************************************************\\
References vs Pointers
Both references and pointers can be used to change local variables of one function inside another function. 
Both of them can also be used to save copying of big objects when passed as arguments to functions or returned from functions, 
to get efficiency gain.
Despite above similarities, there are following differences between references and pointers.

References are less powerful than pointers
1) Once a reference is created, it cannot be later made to reference another object; it cannot be reseated. 
This is often done with pointers.
2) References cannot be NULL. Pointers are often made NULL to indicate that they are not pointing to any valid thing.
3) A reference must be initialized when declared. There is no such restriction with pointers

Due to the above limitations, references in C++ cannot be used for implementing data structures like Linked List, 
Tree, etc. In Java, references don’t have above restrictions, and can be used to implement all data structures. 
References being more powerful in Java, is the main reason Java doesn’t need pointers.

References are safer and easier to use:
1) Safer: Since references must be initialized, wild references like wild pointers are unlikely to exist. It is still 
possible to have references that don’t refer to a valid location (See questions 5 and 6 in the below exercise )
2) Easier to use: References don’t need dereferencing operator to access the value. They can be used like normal variables. 
‘&’ operator is needed only at the time of declaration. Also, members of an object reference can be accessed with 
dot operator (‘.’), unlike pointers where arrow operator (->) is needed to access members.

Together with the above reasons, there are few places like copy constructor argument where pointer cannot be used. 
Reference must be used pass the argument in copy constructor. Similarly references must be used for overloading some operators like ++.
*************************************************************************************************************************/


#include "stdafx.h"
#include "iostream"

using namespace std;

void test_ref();

/*
void swap(int a, int b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}
*/
void swap(int &a,  int &b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}

int &fun()
{
	int a = 10;
	return a;
}

int fun1(int &x)
{
	return x;
}

void swap(char* &str1, char* &str2)
{
	char *& temp = str1;
	str1 = str2;
	str2 = temp;
}

int _tmain(int argc, _TCHAR* argv[])
{
	//case 1
	test_ref();		// simple test

	//case 2
	fun() = 30;
	cout << fun()<<endl;	// if a is static it will print 30 else 10                           // NTC

	//case 3
	//cout<< fun1(10) <<endl;     // this will give error

	//case 4
	char *str1 = "GEEKS";
	char *str2 = "FOR GEEKS";
	swap(str1, str2);
	cout<<"str1 is "<<str1<<endl;
	cout<<"str2 is "<<str2<<endl;

	// case 5
	int x = 10;
    int *ptr = &x;
    // int& *ptr1 = ptr;          //error: pointer to reference is not allowed

	//case 6
	int *ptr1 = NULL;
	//cout << *ptr1;		// throw exception as reading location null
    int &ref = *ptr1;
    //cout << ref;			// throw exception as reading location null

	int a = 100;
	int b = 200;

	std::cout << "a="<<a<<"b="<<b<<std::endl;
	swap(a,b);
	std::cout << "a="<<a<<"b="<<b<<std::endl;

	return 0;
}

void test_ref()
{
	string s1 = "abc";
	string s2 = "def";
	string &ref1 = s1;
	string &ref2 = s2;

	puts(s1.c_str());
	puts(s2.c_str());
	puts(ref1.c_str());
	puts(ref2.c_str());
	
	ref1 = s2;						// because ref1 is always pointing to s1 so the value will replace with s2 value but address
									// pointed by both s1 and ref1 will remain same and both will always share same content.
	puts(s1.c_str());
	puts(s2.c_str());
	puts(ref1.c_str());
	puts(ref2.c_str());
}