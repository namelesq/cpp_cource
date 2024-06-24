//#define INTEGER 
//#define DOUBLE
#define CHAR

#include <iostream>
#include <vector>
#include "function.h"

int main()
{
#ifdef INTEGER
	std::vector<int> Data;
#elif defined(DOUBLE)
	std::vector<double> Data;
#else
	std::vector<char> Data;
#endif
	INPUTDATAINVECTOR(Data);
	PRINTVECTOR(Data);
	SEARCHMINMEANING(Data);
	SEARCHMAXMEANING(Data);
	VECTORSORT(Data);
	EDITVECTOR(Data);

	return 0;
}