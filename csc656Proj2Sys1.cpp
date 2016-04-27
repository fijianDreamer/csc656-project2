// Amrita Singh
// csc 656 Project 2 - Cache Simulation System 1
// Due: Monday, April 25, 2016 
// csc656Proj2Sys1.cpp
/* The purpose of this projet is to write a cache simulator that uses memory
*  address traces as input.
*
*  Instructions on compiling:
*  g++ csc656Proj2Sys1.cpp -o csc656Proj2Sys1
*/

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <math.h>
#include <string>
#include <cstdio>
#include <bitset>
#include <stdlib.h>
using namespace std;

int main(int argc, char* argv[])
{
	long long pcAddr, memAddr, data; 
	int nBytes, c; // The # of bytes read / write (4th item read in)
	char option; // option is W for write or R for read
	int numBlocksOffset, numBlocks, index, tag, in1, in2, i;
	numBlocksOffset = numBlocks = index = tag = in1 = in2 = i = 0;
	int b = 32; // Defined in assignment handout (byte blocks)
	ifstream aTraceFile;
	aTraceFile.open(argv[1]); // Open the file given on the command line
	if (aTraceFile.is_open())
	{
		c = atoi(argv[2]);
		in1 = atoi(argv[4]); // What lines to include starting from 0
		in2 = atoi(argv[5]);
		// Read in a line
		cout << "TraceFile is good!!" << endl;
		while (aTraceFile >> std::hex >> pcAddr >> option >> option >> std::hex >> memAddr >> nBytes >> std::hex >> data)
		{
			//cout << std::hex << pcAddr << option << std::hex << memAddr << nBytes << std::hex << data << endl;
			// Calculate the tag, index, and offset
			// Make sure to show how the memory address is divided into tag, index, and offset
			numBlocksOffset = log2(b); // log base 2 of (32) = 5 --> 2^5 = 32
			numBlocks = ((c * 1024) / b); // ((c*1024) / b)
			index = log2(numBlocks); // log2(c/b)
			tag = b - (numBlocksOffset + index);
			// Create a for loop. This for loop will keep track of the line num as well
			if (i >= in1 && i <= in2) // print line
			{
				cout << std::hex << pcAddr << option << std::hex << memAddr << nBytes << std::hex << data << endl;
				cout << i << endl;
			}
			i++;
		}
		cout << "DONE with while loop" << endl;
		cout << c << endl;
		aTraceFile.close();
		cout << "Trace File closed" << endl;
	}
	else
	{
		// ERROR opening the file. Let user know & exit
		cout << "ERROR: Could not open file" << endl;
	}
	return 0;
}