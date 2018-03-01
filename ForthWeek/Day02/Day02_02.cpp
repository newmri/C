#include <iostream>

using namespace std;

// ##1. typedef

typedef int DATA_TYPE;

typedef struct taginfo
{
	DATA_TYPE	data;
}INFO, *PINFO;

int main()
{
	DATA_TYPE data;
	INFO info;
	PINFO pInfo;
}