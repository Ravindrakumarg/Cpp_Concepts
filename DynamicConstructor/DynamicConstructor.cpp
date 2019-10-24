// DynamicConstructor.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"

class Matrix
{
private:
	int **_hndlr;
	int __row;
	int __coloum;
public:
	void construct_matrix (int row, int coloum);
	void fill_matrix (int x, int y, int value);
	void render_matrix ();

	~Matrix()
	{
		for (int i=0; i<__row; i++)
		{
			delete _hndlr[i];
		}
		delete _hndlr;
		_hndlr = 0;
	}
};

void Matrix :: construct_matrix (int row, int coloum)
{
	int looper;
	__row = row;
	__coloum = coloum;
	_hndlr = new int *[row];
	for ( looper = 0; looper < row; looper++)
	{
		_hndlr[looper] = new int [coloum];
	}
}

void Matrix ::fill_matrix (int x, int y, int value)
{
	_hndlr[x][y] = value;
}

void Matrix :: render_matrix ()
{
	int x, y;
	for ( x= 0; x<__row; x++)
	{
		for ( y=0; y<__coloum; y++)
			std::cout << _hndlr[x][y] << " ";

		std::cout << "\n";
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	int r, c;
	Matrix _matrix;

	std::cout << "Enter the row and coloum";
	std::cin >> r >> c;

	_matrix.construct_matrix(r, c);

	std::cout << "Enter the data row wise:";
	int x, y, value;
	for (x=0; x < r; x++)
	{
		for (y=0; y < c; y++)
		{
			std::cin >> value;
			_matrix.fill_matrix (x, y, value);
		}
		std::cout << "\n";
	}

	std::cout <<"Here is the matrix: \n";
	_matrix.render_matrix();

	return 0;
}