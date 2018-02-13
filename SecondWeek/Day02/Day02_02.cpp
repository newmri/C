#include <iostream>
#include <ctime>

using namespace std;

// ##1. random

int main()
{
	// ##2. rand()
	// Default seed is 1, so same number comes out.
	int n = rand();
	int n2 = rand();

	cout << n << " " << n2 << endl;
	srand(2); // Change seed value.
	n = rand();
	n2 = rand();
	cout << n << " " << n2 << endl;

	// time function

	int iTime = time(nullptr);
	srand(unsigned(time(nullptr)));
	
}	