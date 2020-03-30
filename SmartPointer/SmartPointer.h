
#ifndef __SMART_POINTER_H__
#define __SMART_POINTER_H__

#include "iostream"
#include "RefCount.h"

template <typename T> 
class CSmartPointer
{
private:
	T*			__rect;
	CRefCount*	__reference;

public:
	CSmartPointer () :
					__rect(0), __reference(0)
	{
		__reference = new CRefCount();
		__reference->add_ref();
	}

	explicit CSmartPointer (T* rect):
					__rect(rect), __reference(0)
	{
		__reference = new CRefCount();
		__reference->add_ref();
	}

	CSmartPointer (const CSmartPointer<T>& sp):
					__rect(sp.__rect), __reference(sp.__reference)
	{
		__reference->add_ref();
	}

	~CSmartPointer ()
	{
		if (__rect && __reference->release() == 0)
		{
			delete __reference;
			delete __rect;
		}
	}

	T& operator*()
	{
		return *__rect;
	}

	T* operator->()
	{
		return __rect;
	}

	CSmartPointer<T>& operator = (const CSmartPointer<T> &smt)
	{
		if(this != &smt)
		{
			if(__reference->release() == 0)
			{
				delete __reference;
				delete __rect;
			}

			__rect		= smt.__rect;
			__reference	= smt.__reference;
			__reference->add_ref ();
		}
		return *this;
	}

};
#endif //__SMART_POINTER_H__