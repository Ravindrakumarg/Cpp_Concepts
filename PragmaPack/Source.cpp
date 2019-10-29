#include <iostream>

// #pragma pack( show ) - will show current value
// #pragma pack( push [ , identifier ] [ , n ] )
// #pragma pack( pop [ , { identifier | n } ] )
// #pragma pack( [ n ] )

struct S {
	int i;   // size 4
	short j;   // size 2
	double k;   // size 8
};
#pragma pack(show)

#pragma pack(2)
#pragma pack(show)
struct T {
	int i;
	short j;
	double k;
};

#pragma pack(push, 16)
#pragma pack(show)

struct A
{
	char ch;
	int data;
	int arr[2];
};

int main()
{
	std::cout << "Struct size:" << sizeof(A) << std::endl;

	printf("%zu ", offsetof(S, i));	// offsetof - gives the offset of member in that class/structure
	printf("%zu ", offsetof(S, j));
	printf("%zu\n", offsetof(S, k));

	printf("%zu ", offsetof(T, i));
	printf("%zu ", offsetof(T, j));
	printf("%zu\n", offsetof(T, k));

	getchar();
	return 0;
}