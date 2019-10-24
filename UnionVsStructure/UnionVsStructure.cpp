// UnionVsStructure.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

typedef struct Book
		{
			char	bookName[25];
			int		pageCount;
			float	pricePerPiece;
		} MyBook;

typedef union eBook
		{
			char	bookName[25];
			int		pageCount;
			float	pricePerPiece;
		} MyEBook;

int _tmain(int argc, _TCHAR* argv[])
{
	printf ("\n===================Structure stuff==============================\n\n");
	MyBook b = {"Visual C++", 200, 247.50};
	printf ("Book Name=%s, Total Page=%d, Price=%f \n", b.bookName, b.pageCount, b.pricePerPiece);
	printf ("Size of structure=%d \n", sizeof(b));
	printf ("Size of=%d, %d, %d \n", sizeof(b.bookName), sizeof(b.pageCount), sizeof(b.pricePerPiece));
	printf ("Address of Structure=%u \n", &b);
	printf ("Address of=%u, %u, %u \n", &b.bookName, &b.pageCount, &b.pricePerPiece);

	printf ("\n===================Union stuff==============================\n\n");

	MyEBook e = {"C Programming"};
	printf ("Size of union= %u \n", sizeof(e));
	printf ("Address of union= %u \n", &e);
	printf ("Book name= %s, size=%d, address=%u \n", e.bookName, sizeof(e.bookName), &e.bookName);
	e.pageCount = 240;
	printf("Size of union= %u \n", sizeof(e));
	printf ("Book Page Count= %d, size=%d, address=%u \n", e.pageCount, sizeof(e.pageCount), &e.pageCount);
	printf ("Book name=%s, pagecount=%d, Price=%f \n", e.bookName, e.pageCount, e.pricePerPiece);
	printf ("Address of Book name=%u, pagecount=%u, Price=%u \n", &e.bookName, &e.pageCount, &e.pricePerPiece);

	char test[25];
	printf ("\n\nsize of test= %d \n", sizeof(test));

	struct testS
	{
		char test[25];
	} test1;
	printf ("\n size of struct test= %d, %d \n", sizeof(test1), sizeof(test1.test));

	getc(stdin);
	return 0;
}