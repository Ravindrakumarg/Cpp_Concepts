#include "stdafx.h"

class A{};

class B
{
public:
	explicit B(const A &a) {}

	B& operator = (A &a)
	{
		return * this;
	}
	operator A()
	{
		return A();
	}
};

void fn (B x) {}

int _tmain(int argc, _TCHAR* argv[])
{
	A foo;
	B bar(foo);
	bar = foo;
	foo = bar;

	fn(foo);
	fn(bar);

	return 0;
}