#include <iostream>

using namespace std;

// ##1. Function Overloading
// Redefine same name function by argument.
// Flexibility!

int Add(int a, int b) { cout << "Integer Two Arguments: "; return a + b; }
int Add(int a, int b, int c) { cout << "Integer Three Arguments: "; return a + b + c; }
float Add(float a, float b) { cout << "Float Two Arguments: "; return a + b; }

int main()
{
	cout << Add(1, 2) << endl;
	cout << Add(1, 2, 3) << endl;
	cout << Add(1.1f, 2.2f) << endl;
	system("pause");
}