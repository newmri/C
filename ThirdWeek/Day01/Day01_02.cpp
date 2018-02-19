#include <iostream>

using namespace std;

// ##1. Default Argument
// Define default value.
int Add(int a, int b, int c = 0) { return a + b + c; }

int main()
{
	cout << Add(1,2) << endl;
	cout << Add(1,2,3) << endl;
	system("pause");
}