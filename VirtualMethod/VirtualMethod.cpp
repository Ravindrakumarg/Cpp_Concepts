// VirtualMethod.cpp : Defines the entry point for the console application.
// Implementing the Virtual function Display

#include "stdafx.h"
#include "iostream"

class Media
{
private:
	char *_name;
	float _price;
public:
	Media()
	{
		_name = nullptr;
		_price = 0;
	};
	Media(char *name, float price)
	{
		//std::cout << "in media constructor";
		_name = new char[strlen(name)+1];
		_name= name;
		_price = price;
	}
	virtual ~Media()
	{
		std::cout << "in media distructor";
		delete _name;
	};
	void virtual display()
	{
		std::cout <<"\n" << "Name:"<<_name<<"\nPrice:"<<_price<<"\n";
	}
};

class Book : public Media
{
private:
	int _page_count;
public:
	Book(){};
	Book(char *name, float price, int page_count):Media(name, price)
	{
		//std::cout << "in book constructor\n";
		_page_count = page_count;
	}
	~Book(){ std::cout << "in book distructor"; };
	void display()
	{
		std::cout << "=========Book detail========";
		Media::display();
		std::cout << "Page Count:"<<_page_count<<"\n";
	}
};

class Album : public Media
{
private:
	int _track_count;
public:
	Album(){};
	Album(char *name, float price, int track_count): Media(name, price)
	{
		//std::cout << "in audio constructor";
		_track_count = track_count;
	}
	~Album(){};
	void display()
	{
		std::cout << "=========Album detail========";
		Media::display();
		std::cout << "Total Track Numbers:"<<_track_count<<"\n";
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	Media *_media;
	{
		Book *book = new Book("Hindi", 100.50, 270);
		_media = book;
		_media->display();
		delete _media;
	}
	Album album("English", 150.75, 300);
	_media = &album;
	_media->display();

	getc(stdin);
	return 0;
}