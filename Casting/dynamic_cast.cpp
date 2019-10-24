
#include "Casting.h"
/***************************************************************************************************************************
dynamic_cast can only be used with pointers and references to classes (or with void*). Its purpose 
is to ensure that the result of the type conversion points to a valid complete object of the destination pointer type.

This naturally includes pointer upcast (converting from pointer-to-derived to pointer-to-base), in the same 
way as allowed as an implicit conversion.

But dynamic_cast can also downcast (convert from pointer-to-base to pointer-to-derived) polymorphic classes 
(those with virtual members) if -and only if- the pointed object is a valid complete object of the target type. For example:
****************************************************************************************************************************/


void dynamic_main()
{

}
