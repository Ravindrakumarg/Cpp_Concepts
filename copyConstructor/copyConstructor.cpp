// copyConstructor.cpp : Defines the entry point for the console application.

#include "stdafx.h"
#include "iostream"

class Room
{
private:
	int width;
	int height;
public:
	Room()
	{}
	Room( int w, int h)
	{
		width = w;
		height = h;
	}
	Room (Room &temp)
	{
		this->height	= temp.height;
		this->width		= temp.width;
	}
	Room (Room *temp)
	{
		this->height = temp->height;
		this->width	 = temp->width;
	}
	Room (Room **temp)
	{
		this->height = (*temp)->height;
		this->width	 = (*temp)->width;
	}

	void operator=(Room& temp);

	void display_room();
};

void Room::operator=(Room& temp)
{
	this->height = temp.height;
	this->width = temp.width;
}

void Room :: display_room()
{
	std::cout << "\nheight="<<height<<"   "<<&height<<"\nwidth="<<width<<"   "<<&width << std::endl;
}

int _tmain(int argc, _TCHAR* argv[])
{
	Room room(10, 20);					// call constructor
	room.display_room();

	Room room1 = room;					// copy constructor
	room1.display_room();

	Room room2(room);					// copy constructor
	room2.display_room();

	Room room3;
	room3 = room;						// this is not copy constructor, this is assignment operator
	room3.display_room();

	Room room4(&room);
	room4.display_room();

	Room *room5 = new Room(30, 40);
	room5->display_room();

	Room room6(room5);
	room6.display_room();

	Room room7(&room5);
	room7.display_room();

	getchar();
	return 0;
}