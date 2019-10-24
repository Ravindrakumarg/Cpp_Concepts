
#ifndef __REF_COUNT__
#define __REF_COUNT__

class CRefCount
{
private:
	int __ref_count;

public:
	CRefCount():__ref_count(0)
	{
	}

	void add_ref ()
	{
		__ref_count++;
	}

	int release ()
	{
		__ref_count--;
		return __ref_count;
	}
};

#endif