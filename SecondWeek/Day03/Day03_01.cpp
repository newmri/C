#include <iostream>

using namespace std;

// ##1. function
// Reuse of Code

// Add l,r and return result.
int Add(int lValue, int rValue);
// Print out hello world.
void Display();
void Sum(int n);

// Local variables are in stack.
// Stack is Last In First Out.
// Local variable exists (stack area) with local area, for instance function.
// Allocated when area is started.
// Deallocated when area is ended.

// Global variables
// Global variables exist outer(data area).
// Allocated when program is started.
// Deallocated when program is ended.
// Static is also same as global variable.


int n; // Automatically initialized as 0.

int main()
{
	cout << Add(1, 2) << endl;
	Display();
	cout << n << endl;
	for (int i = 0; i < 3; ++i) Sum(1);
	system("pause");

}

int Add(int lValue, int rValue)
{
	return lValue + rValue;
}

void Display()
{
	cout << "Hello World!" << endl;
}

void Sum(int n)
{
	// Initialized when program is started.
	static int a{};
	a += n;
	cout << a << endl;
}