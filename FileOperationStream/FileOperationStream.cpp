// FileOperationStream.cpp : Defines the entry point for the console application.

/*
 * Simple file operation using the file stream.
 * Author: Ravindra Gupta
 * Date: 1/26/2014 
 */
#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <stdio.h>

#define FILE_NAME	"c:\\file_operation.txt"

void write_to_file()
{
	std::ofstream outfile;
	outfile.open (FILE_NAME, std::ios::out | std::ios::trunc);

	char data[100];

	std::cout << "Enter your full name: ";
	std::cin.getline(data, 100);
	outfile << data << "\n";

	std::cout << "Enter your address: ";
	std::cin.getline(data, 100);
	outfile << data << std::endl;

	std::cout << "Enter your roll number: ";
	std::cin >> data;
	std::cin.ignore();
	outfile << data << std::endl;

	outfile.close();
}

void read_to_file()
{
	std::ifstream infile;
	infile.open (FILE_NAME, std::ios::in);

	char data[100];

	infile >> data;
	std::cout << data <<std::endl;

	infile >> data;
	std::cout << data <<std::endl;

	infile >> data;
	std::cout << data <<std::endl;

	infile.close();
}

int _tmain(int argc, _TCHAR* argv[])
{
	write_to_file();
	write_to_file();

	read_to_file();

	return 0;
}