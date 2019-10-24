
class testconst
{
	int a;
public:
	void display(int p) const
	{
//		a = p;		// a const method can not modify the object(this) or class member variables
	}
	void display1()
	{}
};

int _tmain()
{
	testconst t1;
	t1.display(30);					// with non const object we can access const member
	t1.display1();

	const testconst t2;
	t2.display(7);					// with const object we can access const member only
	//t2.display1();				// this line will give error
									/* this is happending because purpose of creating const object is to not 
									modify the object, but a non const member function can modify member
									so we can't call nonconst member function from const object*/

	return 0;
}

