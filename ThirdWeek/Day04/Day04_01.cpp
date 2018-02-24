#include <iostream>

using namespace std;


// ##1. Function Pointer 
// Pointer contains address of function
// Code of function is stored on data area (memory)
int Add(int a, int b)
{
	return a + b;
}

int main()
{
	// Function name is address of function
	cout << Add << endl;

	// Calling function means visit that address and execute code. 
	cout << Add(1, 2) << endl;

	// Declare Function Pointer
	// Return type(*Pointer)(parameter type)
	int(*ptr)(int, int) = Add;
	cout << ptr(1, 2) << endl;
	system("pause");
}