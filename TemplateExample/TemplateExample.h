
/*
 * Simple class to store the variable
 */

#ifndef __TEMPLATE_EXAMPLE__
#define __TEMPLATE_EXAMPLE__

template <class T>
class MAX_MIN
{
private:
	T first_num;
	T second_num;
public:
	void initialize(T const& a, T const& b)
	{
		first_num  = a;
		second_num = b;
	}

	T getMaximumNumber ()
	{
		return (first_num>second_num) ? first_num:second_num;
	}
};

#endif