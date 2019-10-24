// testProject.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "conio.h"
#include "stdlib.h"
#include "stdio.h"
#include <iostream>
#include <string.h>

using namespace std;

#define AREA(x) (x*x)
#define PRINT(x) printf ("%d", x) 
#define debug(fmt, ...) printf("%s:%d" fmt, __FILE__, __LINE__, __VA_ARGS__);
# define SEMI ;

class test
{
public:
	int _a, _b;
public:
	test(int a, int b)
	{
		_a=a;
		_b=b;
	}
};

class A
{
public:
	A(){};
};

class X
{
public:
	int x;
};

class Test1
{
	int a;
};

unsigned result(unsigned x)
{
	int i = 0;
	while(x)
	{								// x=5   
		x=x&(x-1);					// 1> 101&100=100 so first iteration will return 4
		i++;						// 2> 100&011=000 so second iteration will return 0.
	}
	return i;						// so i will return 2
}

class priv
{
	int a;
	int b;
public:
	priv(int x, int y):a(x), b(y)
	{
	}
};

class Base
{
	int a;
public:
	void get() { cout << "base"; }
	void get(int a) const { a = 30; }
};
class Drived : public Base
{
	void get() { cout << "drived"; }
};

class a {
public:
	a() { std::cout << "base contructor" << std::endl;  fun1(); fun2(); }
	void global() { fun1(); fun2(); }
private:                                                            // private
	virtual void fun1() { std::cout << "f1:base" << std::endl; }    //virtual
	virtual void fun2() = 0 { std::cout << "f2:base" << std::endl; }//pure virtual
};

class b : public a
{
private:
	void fun1() { std::cout << "f1:derived" << std::endl; }
	void fun2() { std::cout << "f2:derived" << std::endl; }
};

int main () /* Use int float and char */
{
	b B;
	B.global();

	Base bb;
	bb.get(20);

	Base* b = new Drived();
	b->get();	// this will call the private get of driver class. it passes compilation because base
				// is having public mumber get but at linking time it will link to drived class get

	//testRef();
	//testSize();
	priv *p = new priv(4, 7);
	void *v = p;						// we can access private member of class like this.
	int m = *(int*)v;
	//int n = *(int*)v++;
	cout << "m="<<m;

	unsigned i = result(5);
	cout << "i="<<i<<endl;

//	Test1 tt;

//	X a = {10};
//	X b = a;
//	cout << a.x << b.x;

	class AA
	{
		int a;
	public:
		void get()
		{}
		virtual void test()=0;
	};// aa; //we can not create object of an abstract class

	//cout << "AA " << sizeof(aa) << endl;

//	A a;

	test t(3, 4);
	cout << t._a <<" " << t._b <<" "<< &t._a<<" "<<&t._b<<endl;

	test t1(2, 7);
	t1=t;
	cout << t1._a <<" " << t1._b <<" "<< &t1._a<<" "<<&t1._b<<endl;

	test* t2 = new test(3, 4);
	cout << t2->_a <<" " << t2->_b <<" "<< &t2->_a<<" "<<&t2->_b<<endl;

	test* t3 = new test(2, 7);
	t3=t2;
	cout << t3->_a <<" " << t3->_b <<" "<< &t3->_a<<" "<<&t3->_b<<endl;

	return 0;
}

void Testsize()
{
	class Empty
	{
	};

	class Derived1 : public Empty
	{};

	class Derived2 : virtual public Empty
	{
		int a;
		int ch;
		int b;
		int c;
	};

	class Derived3 : public Empty
	{
		char c;
	};

	class Derived4 : virtual public Empty
	{
		char c;
	};

	class Dummy
	{
		char c;
	};

	cout << "sizeof(Empty) " << sizeof(Empty) << endl;
	cout << "sizeof(Derived1) " << sizeof(Derived1) << endl;
	cout << "sizeof(Derived2) " << sizeof(Derived2) << endl;
	cout << "sizeof(Derived3) " << sizeof(Derived3) << endl;
	cout << "sizeof(Derived4) " << sizeof(Derived4) << endl;
	cout << "sizeof(Dummy) " << sizeof(Dummy) << endl;
}

void testRef()
{
	string s1 = "abc";
	string s2 = "def";
	string &ref1 = s1;
	string &ref2 = s2;

	puts(s1.c_str());
	puts(s2.c_str());
	puts(ref1.c_str());
	puts(ref2.c_str());
	
	ref1 = s2;

	puts(s1.c_str());
	puts(s2.c_str());
	puts(ref1.c_str());
	puts(ref2.c_str());
}


/*
	char *str1 = new char(30);
	cout << "enter the string"<< endl;
	cin >> str1;

	float x;
	int i;
	char ch;

	x = 2.345;
	i = (int) x;
	ch = (char) x;
	printf ("From float x =%f i =%d ch =%c\n",x,i,ch);

	i = 45;
	x = (float) i;
	ch = (char) i;
	printf ("From int i=%d x=%f ch=%c\n",i,x,ch);

	ch = '*';
	i = (int) ch;
	x = (float) ch;
	printf ("From char ch=%c i=%d x=%f\n",ch,i,x);

	return 0;
}


#if 0
int
main( )
{
	int array[26], i ; 
	for ( i = 0 ; i <= 25 ; i++ ) 
	{ 
		array[i] = 'A' + i ; 
		printf ( "\n%d %c", array[i], array[i] ) ; 
	}



	static int a[ ] = { 0, 1, 2, 3, 4 };
	int *p[ ] = { a, a + 1, a + 2, a + 3, a + 4 };
	printf ( "%u %u %d\n", p, *p, * ( *p ) );
	printf ( "%u %u %d\n", (p+1), *(p+1), *(*p)+5 );


	printf ("a");

	int a[3][4] = {
		1, 2, 3, 4,
		5, 6, 7, 8,
		9, 0, 1, 6
	} ;

	display ( a, 3, 4 ) ;
	//show ( a, 3, 4 ) ;
	//print ( a, 3, 4 ) ;


	int arr[] = {10, 20, 30, 40, 50, 60};
	int arr1[] = {10, 20, 30, 40, 50, 60};
	int i=0;
	
	while (i < 6)
	{
		printf("%u, %d, %d, %d, %d\n", &arr[i], arr[i], *(arr+i), *(i+arr), i[arr]);
		i++;
	}

	
	int arr[ ] = { 10, 20, 30, 45, 67, 56, 74 };
	int *i, *j;
	i = &arr[1];
	j = &arr[5];
	printf ("%d %d %d \n", arr, i, j);
	printf ( "%d %d %f", j - i, *j - *i);
#endif


#if 0
int p = 3 SEMI ;
printf ( "%d", p ) SEMI

float area = AREA(3);
//printf ("%f", area);
PRINT (area);
debug ("This is area of ractangle=%f", area);
#endif
//printf ( "nn \\n\n nn\n" ) ;
//printf ( "nn //n//n nn//n" ) ;

/*int a, b ;
a = -3 - - 3 ;
b = -3 - - ( - 3 ) ;
printf ( "a = %d b = %d", a, b ) ;*/

/*int i = 2, j = 3, k, l ;
float a, b ;
k = i / j * j ;
l = j / i * i ;
a = i / j * j ;
b = j / i * i ;
printf( "%d %d %f %f", k, l, a, b ) ;


int x = 3 ;
float y = 3.0 ;
if ( x == y )
printf ( "\nx and y are equal" ) ;
else
printf ( "\nx and y are not equal" ) ;



int x = 3, y, z ;
y = x = 10 ;
z = x < 10 ;
printf ( "\nx = %d y = %d z = %d", x, y, z ) ;



if ( 'X' < 'x' )
printf ( "\nascii value of X is smaller than that of x" ) ;



int j ;
while ( j <= 10 )
{
printf ( "\n%d", j ) ;
j = j + 1 ;
}

	while ( '1' < '2' )
printf ( "\nIn while loop" ) ;


	int i ;
for ( i = 1 ; i <= 5 ; printf ( "\n%d", i ) ) ;
i++ ;
*/
/*char ch = 9;
printf ("\n %d %c", ch, ch);

int a = 'b'+'c';*/


#if 0
void
display (int * ptr, int row, int col)
{
	int i, j ;
	for ( i = 0 ; i < row ; i++ )
	{
		for ( j = 0 ; j < col ; j++ )
			printf ( "%d ", * ( q + i * col + j ) );
			printf ("\n");
	}
	printf ("\n");
}
#endif