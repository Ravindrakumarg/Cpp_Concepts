#include "stdafx.h"
#include "iostream"

template<typename T>
class Vector
{
private:
	T *_x;
	int _size;
public:
	Vector (int size)
	{
		_size = size;
		_x = new T[size];
		for (int i=0; i<size; i++)
			_x[i]=0;
	}
	Vector (T *value)
	{
		int count;
		for (count=0; count<_size; count++)
			_x[count] = value[count];
	}
	T operator *(Vector &v)
	{
		int count=0;
		T sum =0;
		while (count < 3)
		{
			sum += 1;//this->_x[count] * v._x[count];
			count++;
		}
		return sum;
	}
};


int _tmain(int argc, _TCHAR* argv[])
{
	int x[3]={1,2,3};
	int y[3]={4,5,6};
	Vector<int> vector1(3);
	Vector<int> vector2(3);
//	Vector<int> vector3(1, 2, 4);
	vector1 = x;
	vector2 = y;

	int result = vector1 * vector2;
	std::cout << "Result = "<<result<<"\n";

	return 0;
}