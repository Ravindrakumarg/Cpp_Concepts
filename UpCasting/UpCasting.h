#ifndef UPCASTING_H_INCLUDED
#define UPCASTING_H_INCLUDED

#include "iostream"
using namespace std;
class Parent
{
public:
    void sleep()
    {
        cout << "sleeping"<<endl;
    }
};
class Child : public Parent
{
public:
    void gotoSchool()
    {
        cout << "going school"<<endl;
    }
};
class Operation
{
public:
    void perform_opeartion()
    {
        Parent *p = new Parent();
        Child *c = new Child();

		// this is upcasting(bcz child class object is getting assign to base class ptr
		// but though that we can only access base class feature
        Parent *p1 = c;
        p1->sleep();


		// this is downcasting where parent class object is assigned to child class member
        Child *c1 = (Child*)p;
        c1->gotoSchool();	// parent does not have this method declare so this will give unexpected behaviour.
        c1->sleep();
    }
};
#endif // UPCASTING_H_INCLUDED