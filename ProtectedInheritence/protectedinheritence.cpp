#include <iostream>

// diff bet private and protected is that private members can not be inherited but protected can. But still be
// can accessed frm outside the class boundry.
// diff bet protected and public is that public member can be accesses out side class but protected can not.
// In protected inheritence public members also becomes protected in drived class.
class Base
{
protected:
	int a;
public:
	int get_a() { return a; }
	void set_a(int aa) { a = aa; }
};
class Drive : public Base
{
protected:
	int b;
public:
	int get_b() { return b; }
	void set_b(int bb) { b = bb; }
};

int main()
{
	Drive d;
	d.set_a(10);
	d.set_b(20);
	std::cout << d.get_a() << ", " << d.get_b() << std::endl;
	getc(stdin);
	return 0;
}