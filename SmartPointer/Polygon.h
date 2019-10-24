
#ifndef __POLYGON_H__
#define __POLYGON_H__

#include <iostream>

class CPolygon
{
private:
	int		__vertex_count;
	int**	__sides;

public:
	void get_number_of_vertex (int count)
	{
		__vertex_count = count;
	}

	void constuct_polygon ()
	{
		int* __sides = new int[__vertex_count];
		for (int i=0; i< __vertex_count; i++)
		{
			std::cout << "Enter side data: ";
			std::cin >> __sides[i];
		}
	}

	void Display()
	{
		std::cout << "Polygon side data: ";
		for (int i=0; i< __vertex_count; i++)
		{
			 std::cout << __sides[i] << ", ";
		}
	}
};

#endif //__POLYGON_H__