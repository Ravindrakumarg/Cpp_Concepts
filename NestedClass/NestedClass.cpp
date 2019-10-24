#include <iostream>
using namespace std;

/* in case of nested class where one class holds the object of another class the object creation 
of the class who is holding another class object happen at the end and before that it will create object
of all the containing class, this is called containership or nesting */

class Alpha
{
public:
	Alpha() { cout << "ALpha" << endl; }
};

class Beta
{
public:
	Beta(){ cout << "Beta" << endl;  }
};

class Gamma
{
	Alpha a;
	Beta b;
public:
	Gamma() : b(), a()		// here it will call Alpha first then Beta
	{ cout << "Gamma" << endl; }
};

int main()
{
	Gamma g;

	getchar();
	return 0;
}