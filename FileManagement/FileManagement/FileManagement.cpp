// FileManagement.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include "Windows.h"
#include "TCHAR.h"

#define SOURCE_FILE "c:\\users\\ravindrakumarg\\Documents\\dsa.pdf"
#define DEST_FILE	"d:\\dsa.pdf" 
#define debug(arg, ...) printf("\nLine:%d: " arg, __LINE__, __VA_ARGS__);

#if 0
#if _UNICODE
	typedef MYTCHAR wchar_t;
#else
	typedef MYTCHAR char;
#endif
#endif

int _tmain(int argc, _TCHAR* argv[])
{
	TCHAR *source_file;
	TCHAR *target_file;

	source_file = (TCHAR *) SOURCE_FILE;
	target_file = (TCHAR *) DEST_FILE;
	
	debug ("sourcefile:%ls", source_file);
	debug ("dest_file :%ls", target_file);

	HRESULT hr;
	hr = CopyFileW (source_file, target_file, false);
	if (hr)
	{
		debug ("Error occurred while coping=%d", GetLastError());
	}

	debug ("File copied successfully");




	return 0;
}