#include <iostream>
#include "UpCasting.h"

using namespace std;

/* upcasting is when drived class pointer(or ref) is assigned to base class pointer.
   is this case through base class ptr only base class feature can be accesses.
   This is mainly used in polymorphism where a common function can work for all class */

/* downcasting happen when base class object is assigned to child class pointer. This is a explicit operation.
   Downcasting is not safe as upcasting. Because if ptr to try to access the child class feature that will be
   missing in base class object that any unexpected behaviour can happen */

/* safe way of casting is use dynamic_cast. which will check compatiblity and give error while duing wrong */

int main()
{
    Operation ope;
    ope.perform_opeartion();

    return 0;
}
